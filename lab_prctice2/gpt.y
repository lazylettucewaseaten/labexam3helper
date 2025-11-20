%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
void yyerror(const char *s){ printf("Syntax Error: %s\n", s); exit(1);}
%}

%token ROUNDLBRACKET ROUNDRBRACKET ZERO ONE IDENTIFIER IF ELSE SEMICOLON COMMA
%token PLUS MINUS MULT DIV
%right UNARY
%left PLUS MINUS
%left MULT DIV
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program

%%

program : stmts ;

stmts : /* empty */
      | stmts stmt
      ;

stmt : binary SEMICOLON
     | IDENTIFIER SEMICOLON
     | arithmetic SEMICOLON
     | function_call SEMICOLON
     | ifstmt
     | parens
     ;

binary : ZERO
       | ONE
       | binary ZERO
       | binary ONE
       ;

parens : ROUNDLBRACKET parens ROUNDRBRACKET parens
       | /* empty */
       ;

arithmetic : arithmetic PLUS arithmetic
           | arithmetic MINUS arithmetic
           | arithmetic MULT arithmetic
           | arithmetic DIV arithmetic
           | MINUS arithmetic %prec UNARY
           | ROUNDLBRACKET arithmetic ROUNDRBRACKET
           | IDENTIFIER
           | ZERO
           | ONE
           ;

function_call : IDENTIFIER ROUNDLBRACKET args ROUNDRBRACKET ;

args : /* empty */
     | arglist
     ;

arglist : IDENTIFIER
        | function_call
        | IDENTIFIER COMMA arglist
        | function_call COMMA arglist
        ;

ifstmt : IF ROUNDLBRACKET IDENTIFIER ROUNDRBRACKET stmt %prec LOWER_THAN_ELSE
       | IF ROUNDLBRACKET IDENTIFIER ROUNDRBRACKET stmt ELSE stmt
       ;

%%

int main() {
    if (yyparse() == 0) printf("Parsing successful!\n");
    return 0;
}

