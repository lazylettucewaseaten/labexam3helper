%{
	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	#include "symbol.h"

	int yylex();
	void yyerror(const char* s) { fprintf(stderr, "%s\n", s); }

	char currentType[20];
	int currentScope = 0;
%}

%union {
    char* str;
}

%token <str> ID ADD SUB MUL DIV MODULO OR AND NOT TRUE_ FALSE 
%token INT FLOAT CHAR

%%

program:
        program declaration
        | declaration
        ;

declaration:
        type id_list ';'
        ;

type:
        INT   { strcpy(currentType, "int"); }
      | FLOAT { strcpy(currentType, "float"); }
      ;

id_list:
        ID               { insertSymbol($1, currentType, currentScope); }
      | id_list ',' ID   { insertSymbol($3, currentType, currentScope); }
      ;
      

arithexp: 
	arithexp ADD arithexp| arithexp SUB arithexp | arithexp MUL arithexp | arithexp DIV arithexp | arithexp MODULO arithexp |
	arithexp  RELOP arithexp | arithexp OR arithexp | arithexp AND arithexp | NOT arithexp | TRUE_ | FALSE_ | ID;


RELOP : LT|GT|LT EQ |GT EQ | EQ EQ | NOT EQ;

%%

int main() {
    yyparse();
    return 0;
}

