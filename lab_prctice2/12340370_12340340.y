%{
#include<stdio.h>
#include<stdlib.h>


extern int yylex();
extern FILE* yyin;
%}


%token INT DOUBLE BOOL STRING VOID  MAIN ROUNDLBRACKET ROUNDRBRACKET SEMICOLON FOR BOOLEAN STRING_LITERAL THEN ZERO ONE FACT
%token IDENTIFIER MULTIPLITIVE ADDITIVE RELATIONAL EQUALITY AND OR ASSIGNMENT NEW CURLYRBRACKET  CURLYLBRACKET SWITCH CASE  COLON
%token CLASS NUMBER COMMA NEWARRAY UNARY RETURN BREAK IF ELSE DO WHILE SQUARERBRACKET DOT SQUARELBRACKET ELIF


%right ASSIGNMENT        // a = b = c (evaluated as a = (b = c))
%left OR                 // ||
%left AND                // &&
%left EQUALITY           // ==, !=
%left RELATIONAL         // <, <=, >, >=
%left ADDITIVE           // +, -
%left MULTIPLITIVE       // *, /, %
%right UNARY             // !, - (unary)
%left DOT SQUARELBRACKET SQUARERBRACKET  // object.field, array[index]

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%start program

%%
program : Stmts ;
Stmts : Stmts Stmt |   ; 
Stmt :  type identifiersmany SEMICOLON | 
Arithmetic SEMICOLON | factorial |

palindrome | binary |
 forloop Stmt SEMICOLON  | conditionalstmt SEMICOLON | switchstmt | bracketseq  
| array ;

type : INT | DOUBLE | STRING ;

curlystmts : CURLYLBRACKET Stmts CURLYRBRACKET 
identifiersmany : identifiersmany COMMA IDENTIFIER   | IDENTIFIER ;
forloop : FOR ROUNDLBRACKET Arithmetic SEMICOLON Arithmetic SEMICOLON ROUNDRBRACKET Arithmetic ;
conditionalstmt : ifthen | ifthenelse | ifthenelif;
ifthen : IF ROUNDLBRACKET Arithmetic ROUNDRBRACKET THEN curlystmts %prec LOWER_THAN_ELSE;
ifthenelse : ifthen ELSE curlystmts; 
ifthenelif : ifthen ELIF ROUNDLBRACKET Arithmetic ROUNDRBRACKET curlystmts ELSE curlystmts ;
switchstmt : SWITCH ROUNDLBRACKET Arithmetic ROUNDRBRACKET CURLYLBRACKET case_list CURLYRBRACKET 
case_list : case_list case_list_temp | ;
case_list_temp : CASE NUMBER COLON Stmt ;

bracketseq :  ROUNDLBRACKET bracketseq ROUNDRBRACKET bracketseq | ROUNDLBRACKET ROUNDRBRACKET ;

binary : ZERO | ONE; 
palindrome : CLASS ;

factorial : FACT factinner ;
factinner : ROUNDLBRACKET factorial ROUNDRBRACKET | ROUNDLBRACKET FACT ROUNDRBRACKET ;
Arithmetic : Arithmetic ADDITIVE Arithmetic |Arithmetic MULTIPLITIVE Arithmetic | UNARY Arithmetic | Arithmetic RELATIONAL Arithmetic | Arithmetic EQUALITY Arithmetic | Arithmetic AND Arithmetic | Arithmetic OR Arithmetic   | Operand ;

Operand  : IDENTIFIER | ROUNDLBRACKET Arithmetic ROUNDRBRACKET ;
//   () * ( () + () )  

array : SQUARELBRACKET arrayinner SQUARERBRACKET ;
arrayinner :  arrayinner COMMA IDENTIFIER | arrayinner COMMA array | array | IDENTIFIER;

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



