%{
#include<stdio.h>
#include<stdlib.h>


extern int yylex();
extern FILE* yyin;
%}

%token LABEL SEMICOLON REGISTER CONST ADD MUL SUB DIV MOV JMP   COMMA IMMEDIATE LOAD COLON STORE HALT ;

%start program

%%

program : Stmts  ;
Stmts : Stmts optional Stmt  suffix |  ;
optional : LABEL COLON | ;
suffix : SEMICOLON | ;
Stmt:  Arithmetic | Conditional | Memory | Halt ;
Arithmetic : arith_start  REGISTER  COMMA last;
last :  REGISTER | IMMEDIATE ;
arith_start :  MOV | ADD | MUL | SUB | DIV;
Conditional : JMP LABEL ;
Memory : mem_start REGISTER COMMA IMMEDIATE ;
Halt : HALT ;
mem_start : LOAD | STORE ;
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



