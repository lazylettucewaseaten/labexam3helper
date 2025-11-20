%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);

int temp_count=0;
int label_count=0;

char* new_temp(){
    char *temp=(char*)malloc(10);
    sprintf(temp,"t%d",temp_count++);
    return temp;
}

char* new_label(){
    char *label=(char*)malloc(10);
    sprintf(label,"L%d",label_count++);
    return label;
}

%}

%union {
    int num;
    float fnum;
    char *str;
    struct {
        char* place;
        char* code;
    } b;
}

%token INT FLOAT BOOL STRING VOID ROUNDLBRACKET ROUNDRBRACKET SEMICOLON FOR BOOLEAN 
%token MULTIPLITIVE ADDITIVE RELATIONAL EQUALITY AND OR ASSIGNMENT NEW CURLYRBRACKET CURLYLBRACKET
%token CLASS COMMA NEWARRAY UNARY RETURN BREAK IF ELSE DO WHILE SQUARERBRACKET DOT SQUARELBRACKET
%token NOT LT GT LE GE EQ NE
%token MAIN TRUELIT FALSELIT
%token<str> IDENTIFIER
%token<num>NUMBER
%token<fnum>FNUMBER
%token '+' '-' '*' '/'

/* Declare types for non-terminals */
%type<b> booleanExp
%type<str> OperatorExp OperatorOperand OperatorTerm Expression ExpressionMain type AssignExp OptionalExp Statement
%type<str> Lvalue RelationalExp ConditionalStmt LoopStmt StmtBlock WhileStmt idlist idlistarr BooleanExp
/* The helper rule must return a string (the label) */
%type<str> if_part while_start while_cond 

%start program

%left DOT SQUARELBRACKET SQUARERBRACKET
%left UNARY
%left MULTIPLITIVE
%left ADDITIVE
%left RELATIONAL
%left EQUALITY
%left OR
%left AND
%left ASSIGNMENT
%right UMINUS
%right UNOT

/* Precedence to fix Dangling Else */
%nonassoc IF_WITHOUT_ELSE
%nonassoc ELSE

%%

program : FuncMain ;

FuncMain : VOID MAIN ROUNDLBRACKET ROUNDRBRACKET StmtBlock ;
    

VarDecl:
       type idlist  SEMICOLON {}
       |
       type idlistarr  SEMICOLON{}
       ;

idlist : idlist COMMA IDENTIFIER {
    Symbol* sym=lookupSymbol($3);
    if(sym!=NULL){
        printf("Error: Variable '%s' is already declared!\n",$3);
        exit(1);
    }
    /* $<str>0 refers to the 'type' rule before idlist */
    insertSymbol($3,$<str>0,0);
    $$=$3;
}
|
IDENTIFIER{
    Symbol* sym=lookupSymbol($1);
    if(sym!=NULL){
        printf("Error: Variable '%s' is already declared!\n",$1);
        exit(1);
    }
    insertSymbol($1,$<str>0,0);
    $$=$1;
};

idlistarr : idlistarr COMMA IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET {
    Symbol* sym=lookupSymbol($3);
    if(sym!=NULL){
        printf("Error: Variable '%s' is already declared!\n",$3);
        exit(1);
    }
    insertSymbol($3,$<str>0,0);
    $$=$3;
}
|
IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET {
    Symbol* sym=lookupSymbol($1);
    if(sym!=NULL){
        printf("Error: Variable '%s' is already declared!\n",$1);
        exit(1);
    }
    insertSymbol($1,$<str>0,0);
    $$=$1;
}


type : INT {$$=strdup("int");} | FLOAT {$$=strdup("float");} ;

ExpressionMain:
    Expression{$$=$1;}
    |
    AssignExp{$$=$1;};

Expression:
    OperatorExp{$$=$1;}
    |
    BooleanExp{$$=$1;}; /* Extract place from struct */

OptionalExp: 
    ExpressionMain{$$=$1;}
    ;

Lvalue:
      IDENTIFIER{
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        $$=$1;
      }
      ;

AssignExp:
    Lvalue ASSIGNMENT ExpressionMain{
        printf("%s = %s\n",$1,$3);
        $$=$1; 
    };
     
OperatorExp:
    OperatorExp '+' OperatorTerm{
        char *temp=new_temp();
        printf("%s = %s + %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp '-' OperatorTerm{
        char *temp=new_temp();
        printf("%s = %s - %s\n",temp,$1,$3);
        $$=temp;
    }
    | OperatorTerm{
        $$=$1;
    }
    ;

OperatorTerm: 
    OperatorTerm '*' OperatorOperand{
        char *temp=new_temp();
        printf("%s = %s * %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorTerm '/' OperatorOperand{
        char *temp=new_temp();
        printf("%s = %s / %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorOperand{
        $$=$1;
    }
    ;

OperatorOperand:
    ROUNDLBRACKET OperatorExp ROUNDRBRACKET {
        $$=$2;
    }
    |
    '-' OperatorOperand %prec UMINUS{
        char *temp=new_temp();
        printf("%s = -%s\n",temp,$2);
        $$=temp;
    }
    |
    NUMBER {
        char *temp=(char*)malloc(20);
        sprintf(temp,"%d",$1);
        $$=temp;
    }
    |
    FNUMBER {
        char *temp=(char*)malloc(20);
        sprintf(temp,"%.2f",$1);
        $$=temp;
    }
    |
    IDENTIFIER{
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        $$=$1;
    }
    |
    IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET {
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        $$=$1;
    }
    ;

BooleanExp :
    booleanExp{
        
    }

booleanExp:
    booleanExp OR booleanExp {
        char *temp=new_temp();
        printf("%s = %s || %s\n",temp,$1.place,$3.place);
        $$.place=temp;
        $$.code="";
    }
    |booleanExp AND booleanExp {
        char *temp=new_temp();
        printf("%s = %s && %s\n",temp,$1.place,$3.place);
        $$.place=temp;
        $$.code="";
    }
    |NOT booleanExp %prec UNOT{
        char *temp=new_temp();
        printf("%s = !%s\n",temp,$2.place);
        $$.place=temp;
        $$.code="";
    }
    |TRUELIT{
        $$.place=strdup("true");
        $$.code="";
    }
    |FALSELIT{
        $$.place=strdup("false");
        $$.code="";
    }
    | ROUNDLBRACKET booleanExp ROUNDRBRACKET { 
        $$=$2;
    }
    | RelationalExp {
        $$.place=$1;
        $$.code="";
    };

RelationalExp:
    OperatorExp LT OperatorExp{
        char *temp=new_temp();
        printf("%s = %s < %s\n",temp,$1,$3);
        $$=temp;
    }   
    |
    OperatorExp GT OperatorExp{
        char *temp=new_temp();
        printf("%s = %s > %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp LE OperatorExp{
        char *temp=new_temp();
        printf("%s = %s <= %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp GE OperatorExp{
        char *temp=new_temp();
        printf("%s = %s >= %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp EQ OperatorExp{
        char *temp=new_temp();
        printf("%s = %s == %s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp NE OperatorExp{
        char *temp=new_temp();
        printf("%s = %s != %s\n",temp,$1,$3);
        $$=temp;
    }  
    ;

StmtBlock: CURLYLBRACKET Stmts CURLYRBRACKET { $$=""; };

Stmts : Statement Stmts | VarDecl Stmts | ;

Statement : 
  OptionalExp SEMICOLON { $$=$1; } 
| ConditionalStmt { $$=$1; }
| LoopStmt  { $$=$1; }
| StmtBlock { $$=$1; }
;

/* ----------------------------------------------------------- */
/* RESOLVED IF/ELSE LOGIC WITH SHARED RULE           */
/* ----------------------------------------------------------- */

/* if_part is a helper rule. It parses "IF ( exp )".
   It creates the True/False labels and prints the jump logic.
   It returns the 'false_label' so the parent can use it later.
*/
if_part: 
    IF ROUNDLBRACKET booleanExp ROUNDRBRACKET 
    {
        char* l_true = new_label();
        char* l_false = new_label();
        
        printf("if %s goto %s \n", $3.place, l_true);
        printf("goto %s\n", l_false);
        printf("%s :\n", l_true);
        
        $$ = l_false; /* Return the false label up the tree */
    }
;

ConditionalStmt: 
    /* Case 1: IF without ELSE */
    if_part Statement %prec IF_WITHOUT_ELSE   
    {
        char* l_false = $1; /* Get label from if_part */
        printf("%s :\n", l_false);
    }
    
    /* Case 2: IF with ELSE */
    | if_part Statement ELSE 
    {
        /* This action runs AFTER the 'if' statement, but BEFORE 'else' statement */
        char* l_exit = new_label();
        char* l_false = $1; /* Get label from if_part */
        
        printf("goto %s\n", l_exit); /* Jump over the else block */
        printf("%s :\n", l_false);   /* Start the else block */
        
        $<str>$ = l_exit; /* Pass exit label to the end */
    }
    Statement    
    {
        char* l_exit = $<str>4; /* Retrieve exit label */
        printf("%s :\n", l_exit);
    }
;

/* ----------------------------------------------------------- */
/* WHILE LOOP LOGIC                      */
/* ----------------------------------------------------------- */

/* ========================================== */
/* WHILE LOOP (Clean Helper Rule Version)     */
/* ========================================== */

LoopStmt : WhileStmt { $$=$1; };

/* Helper Rule 1: while_start
   - Matches the 'WHILE' keyword.
   - Creates the label for the top of the loop.
   - PRINTS: "L_start :"
   - RETURNS: "L_start" (so we can jump back to it later)
*/
while_start: 
    WHILE 
    {
        char* l_start = new_label();
        printf("%s :\n", l_start);
        $$ = l_start; 
    }
;

/* Helper Rule 2: while_cond
   - Matches "( booleanExp )"
   - Creates body and end labels.
   - PRINTS: "if true goto Body", "goto End", "Body :"
   - RETURNS: "L_end" (so we can print the exit label later)
*/
while_cond:
    ROUNDLBRACKET booleanExp ROUNDRBRACKET
    {
        char* l_body = new_label();
        char* l_end = new_label();
        
        printf("if %s goto %s\n", $2.place, l_body);
        printf("goto %s\n", l_end);
        printf("%s :\n", l_body);
        
        $$ = l_end;
    }
;

/* Main Rule: WhileStmt
   - Combines everything.
   - $1 is "L_start" (from while_start)
   - $2 is "L_end"   (from while_cond)
   - $3 is Statement
*/
WhileStmt: 
    while_start while_cond Statement 
    {
        char* l_start = $1; /* Automatically available from stack */
        char* l_end   = $2; /* Automatically available from stack */
        
        printf("goto %s\n", l_start); /* Loop back to top */
        printf("%s :\n", l_end);      /* Exit label */
    }
;

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }

    if (yyparse() == 0) {
        printf("Parsing Successful.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}

void yyerror(const char *s) {
    printf("Semantics Error: %s\n", s);
    printf("Exiting the analysis \n");
    exit(1);
}