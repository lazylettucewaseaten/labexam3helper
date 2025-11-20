%{
#include<stdio.h>
#include<stdlib.h>

extern int yylex();
extern FILE* yyin;
%}

%token INT DOUBLE BOOL STRING VOID  MAIN ROUNDLBRACKET ROUNDRBRACKET SEMICOLON FOR BOOLEAN STRING_LITERAL
%token IDENTIFIER MULTIPLITIVE ADDITIVE RELATIONAL EQUALITY AND OR ASSIGNMENT NEW CURLYRBRACKET  CURLYLBRACKET
%token CLASS NUMBER COMMA NEWARRAY UNARY RETURN BREAK IF ELSE DO WHILE SQUARERBRACKET DOT SQUARELBRACKET
%start program

%left DOT SQUARELBRACKET SQUARERBRACKET

%left UNARY
%left MULTIPLITIVE
%left ADDITIVE
%left RELATIONAL
%left EQUALITY
%left AND
%left OR
%left ASSIGNMENT



%nonassoc IF_WITHOUT_ELSE
%nonassoc ELSE


%%

program : FuncMain declarations
        | declarations_plus FuncMain declarations
        ;

declarations: | declarations declaration ;

declarations_plus: declaration | declarations_plus declaration;




declaration: VarDecl | FuncDecl | ClassDecl  ;

FuncMain : VOID MAIN ROUNDLBRACKET ROUNDRBRACKET StmtBlock
	

VarDecl:
       type IDENTIFIER SEMICOLON 
       |
       IDENTIFIER NEWARRAY ROUNDLBRACKET  NUMBER  COMMA type ROUNDRBRACKET SEMICOLON
       ;

FuncDecl:
	type IDENTIFIER ROUNDLBRACKET formalParameters ROUNDRBRACKET StmtBlock 
	;
	
ClassDecl:
	CLASS IDENTIFIER CURLYLBRACKET FieldList CURLYRBRACKET
	;

FieldList:
    
    | 
    FieldList field 
    ;
	
field: VarDecl | FuncDecl;
type : INT | DOUBLE | BOOL | STRING | VOID ;

formalParameters:  | formalParameterList;

formalParameterList: formalParameter | formalParameterList COMMA formalParameter;

formalParameter: type IDENTIFIER;

Expression:
	OperatorExp
	|
	AssignExp
	|  
	CallExp
	|
	NewExp
	;

OptionalExp: 
	Expression
	|
	;
NewExp:
      NEW ROUNDLBRACKET IDENTIFIER ROUNDRBRACKET;

AssignExp:
	Lvalue ASSIGNMENT Expression;
	
Lvalue:
      IDENTIFIER
      |
      Expression DOT IDENTIFIER
      |
      Expression SQUARELBRACKET Expression SQUARERBRACKET
      ;
      
CallExp:
	IDENTIFIER ROUNDLBRACKET ActualParameters ROUNDRBRACKET 
	|
	Expression DOT IDENTIFIER ROUNDLBRACKET ActualParameters ROUNDRBRACKET 
	;

ActualParameters: | ActualParametersList;
ActualParametersList : Expression | ActualParametersList COMMA Expression;

OperatorExp:
    OrExp
    ;

OrExp:
    AndExp
    | OrExp OR AndExp
    ;

AndExp:
    EqualityExp
    | AndExp AND EqualityExp
    ;

EqualityExp:
    RelationalExp
    | EqualityExp EQUALITY RelationalExp
    ;

RelationalExp:
    AdditiveExp
    | RelationalExp RELATIONAL AdditiveExp
    ;

AdditiveExp:
    MultiplicativeExp
    | AdditiveExp ADDITIVE MultiplicativeExp
    ;

MultiplicativeExp:
    UnaryExp
    | MultiplicativeExp MULTIPLITIVE UnaryExp
    ;

UnaryExp:
    Operand
    | UNARY UnaryExp
    ;
       
Operand: 
    IDENTIFIER
    | DOUBLE
    | NUMBER
    | ROUNDLBRACKET OperatorExp ROUNDRBRACKET 
    ;



StmtBlock: CURLYLBRACKET Stmts CURLYRBRACKET;

Stmts :   Statement Stmts |  VarDecl Stmts | ;

Statement : OptionalExp SEMICOLON |ConditionalStmt | LoopStmt | OtherStmt| StmtBlock;


ConditionalStmt: IF ROUNDLBRACKET OptionalExp ROUNDRBRACKET Statement %prec IF_WITHOUT_ELSE   
               | IF ROUNDLBRACKET OptionalExp ROUNDRBRACKET Statement ELSE Statement
               ;
               
LoopStmt : WhileStmt | ForStmt | DoWhileStmt;

OtherStmt : ReturnStmt | BreakStmt ;

WhileStmt: WHILE ROUNDLBRACKET OptionalExp ROUNDRBRACKET Statement ;

DoWhileStmt: DO Statement WHILE ROUNDLBRACKET OptionalExp ROUNDRBRACKET SEMICOLON ;

ForStmt: FOR ROUNDLBRACKET OptionalExp SEMICOLON OptionalExp SEMICOLON OptionalExp ROUNDRBRACKET Statement ;

BreakStmt:BREAK SEMICOLON ;

ReturnStmt : RETURN OptionalExp SEMICOLON ;


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
    printf("Error: %s\n", s);
    printf("Exiting the analysis \n");
    exit(1);
} 







