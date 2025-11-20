%{
#include<stdio.h>
#include<stdlib.h>
%}

%token MOV ADD SUB MUL DIV LOAD STORE JMP CMP HALT CONST LABEL REGISTER IMMEDIATE COMMA COLON SEMICOLON

%start program

%%
program : stmts ;

stmts : prefix stmt comment stmts | ;

stmt: conditional | halt | arithmetic | memory; 

arithmetic: arith_operator REGISTER COMMA operand_arith;

arith_operator : MOV |ADD | SUB | MUL |DIV ;

operand_arith : REGISTER | IMMEDIATE;


conditional: JMP LABEL ;

memory: memory_start REGISTER COMMA IMMEDIATE;

memory_start: LOAD | STORE ;

halt : HALT ;

comment: SEMICOLON | ;

prefix: LABEL COLON | ; 
%%



void main(){

	yyparse();
    printf("Parsing successfull\n");
}


void yyerror(const char *s) {
    printf("Error: %s\n", s);
    exit(1);
    return ;
}
