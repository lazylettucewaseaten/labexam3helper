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

%token INT FLOAT BOOL STRING VOID  ROUNDLBRACKET ROUNDRBRACKET SEMICOLON FOR BOOLEAN 
%token  MULTIPLITIVE ADDITIVE RELATIONAL EQUALITY AND OR ASSIGNMENT NEW CURLYRBRACKET  CURLYLBRACKET
%token CLASS COMMA NEWARRAY UNARY RETURN BREAK IF ELSE DO WHILE SQUARERBRACKET DOT SQUARELBRACKET
%token NOT LT GT LE GE EQ NE
%token MAIN TRUELIT FALSELIT
%token<str> IDENTIFIER
%token<num>NUMBER
%token<fnum>FNUMBER
%type<b>booleanExp
%token '+' '-' '*' '/'

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
%type<str>OperatorExp OperatorOperand OperatorTerm   Expression ExpressionMain type AssignExp BooleanExp OptionalExp Statement
%type<str>Lvalue  RelationalExp ConditionalStmt LoopStmt StmtBlock WhileStmt idlist  if_pref idlistarr whilestart whilecond
%nonassoc IF_WITHOUT_ELSE
%nonassoc ELSE


%%

program : FuncMain ;

FuncMain : VOID MAIN ROUNDLBRACKET ROUNDRBRACKET StmtBlock
	

VarDecl:
       type idlist  SEMICOLON {}
       |
       type idlistarr  SEMICOLON{}
       ;

idlist : idlist COMMA IDENTIFIER {
    Symbol* sym=lookupSymbol($3);
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",$3);
                exit(1);
            }
     insertSymbol($3,$<str>0,0);
        $$=$3;
}
|
IDENTIFIER{
    Symbol* sym=lookupSymbol($1);
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",$1);
                exit(1);
            }
     insertSymbol($1,$<str>0,0);
        $$=$1;
};

idlistarr : idlistarr COMMA IDENTIFIER SQUARELBRACKET   NUMBER SQUARERBRACKET {
    Symbol* sym=lookupSymbol($3);
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",$3);
                exit(1);
            }
     insertSymbol($3,$<str>0,0);
        $$=$3;
}
|
IDENTIFIER SQUARELBRACKET NUMBER SQUARERBRACKET {
    Symbol* sym=lookupSymbol($1);
            if(sym!=NULL){
                printf("Error: Variable '%s' is  already declared!\n",$1);
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
    BooleanExp{$$=$1;};

OptionalExp: 
	ExpressionMain{$$=$1;}
	
	;
//last me karunga
	
Lvalue:
      IDENTIFIER{
        Symbol* sym=lookupSymbol($1);
        if(sym==NULL){
             printf("Error: Variable '%s' not declared!\n",$1);
            exit(1);
        }
        $$=$1;
      }
    //   |
    //   Expression DOT IDENTIFIER{

    //   }
    //   |
    //   Expression SQUARELBRACKET Expression SQUARERBRACKET{


    //   } removed for now 
      ;
AssignExp:
	Lvalue ASSIGNMENT ExpressionMain{
        printf("%s=%s\n",$1,$3);
    };
     
OperatorExp:
    
    OperatorExp '+' OperatorTerm{
        char *temp=new_temp();
        printf("%s=%s+%s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp '-' OperatorTerm{
        char *temp=new_temp();
        printf("%s=%s-%s\n",temp,$1,$3);
        $$=temp;
    }
    | OperatorTerm{
        $$=$1;
    }
    ;

OperatorTerm: 
    OperatorTerm '*' OperatorOperand{
        char *temp=new_temp();
        printf("%s=%s*%s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorTerm '/' OperatorOperand{
        char *temp=new_temp();
        printf("%s=%s/%s\n",temp,$1,$3);
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
        printf("%s=-%s\n",temp,$2);
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
        printf("%s=%s||%s\n",temp,$1.place,$3.place);
        $$.place=temp;
        $$.code="";
    }
    |booleanExp AND booleanExp {
        char *temp=new_temp();
        printf("%s=%s&&%s\n",temp,$1.place,$3.place);
        $$.place=temp;
        $$.code="";
    }
    |NOT booleanExp %prec UNOT{
        char *temp=new_temp();
        printf("%s=!%s\n",temp,$2.place);
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
        printf("%s=%s<%s\n",temp,$1,$3);
        $$=temp;
    }   
    |
    OperatorExp GT OperatorExp{
        char *temp=new_temp();
        printf("%s=%s>%s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp LE OperatorExp{
        char *temp=new_temp();
        printf("%s=%s<=%s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp GE OperatorExp{
        char *temp=new_temp();
        printf("%s=%s>=%s\n",temp,$1,$3);
        $$=temp;
    }
    |
    OperatorExp EQ OperatorExp{
        char *temp=new_temp();
        printf("%s=%s==%s\n",temp,$1,$3);
        $$=temp;
    }

    |
    OperatorExp NE OperatorExp{
        char *temp=new_temp();
        printf("%s=%s!=%s\n",temp,$1,$3);
        $$=temp;
    }  
    ;


StmtBlock: CURLYLBRACKET Stmts CURLYRBRACKET {};

Stmts :   Statement Stmts |  VarDecl Stmts | ;

Statement : OptionalExp SEMICOLON   { 
    $$=$1;
} 
|
ConditionalStmt {$$=$1;}
| LoopStmt  {$$=$1;}
;

if_pref : IF ROUNDLBRACKET booleanExp ROUNDRBRACKET {
    char * true_label=new_label();
    char * false_label=new_label();

    printf("if %s goto %s\n",$3.place,true_label);
    printf("goto %s\n",false_label);
    printf("%s : \n",true_label);
    $$=false_label;
    
}

ConditionalStmt: if_pref Statement %prec IF_WITHOUT_ELSE     {
   printf("%s :\n",$1);
}

| if_pref Statement ELSE{
    char* ifexit=new_label();
    printf("%s :\n",ifexit);
    printf("%s :\n",$1);
    $<str>$=ifexit;

} Statement    {
    char *ifexit=$<str>4;
    printf("%s :\n",ifexit);
}
;
               
LoopStmt : WhileStmt  {
    $$=$1;
};


whilestart : WHILE {
    char* whilebegin=new_label();
    printf("%s : \n",whilebegin);
    $$=whilebegin;
}
whilecond : ROUNDLBRACKET booleanExp ROUNDRBRACKET {
    char* condtrue=new_label();
    char* condfalse=new_label();
    printf("if %s goto %s\n",$2.place,condtrue);
    printf("goto %s \n",condfalse);
    printf("%s :\n",condtrue);
    $$=condfalse;
}

WhileStmt: whilestart whilecond Statement {
   printf("goto %s\n",$1);
   printf("%s : \n",$2);
};

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
        printf("Parsing Successfull.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}

void yyerror(const char *s) {
    printf("Sematics Error: %s\n", s);
    printf("Exiting the analysis \n");
    exit(1);
} 







