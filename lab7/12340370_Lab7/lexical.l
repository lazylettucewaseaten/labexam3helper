%{
#include<stdio.h>
#include "y.tab.h"
%}

%%
"MOV" {return MOV;}
"ADD" {return ADD;}
"SUB" {return SUB;}
"MUL" {return MUL;}
"DIV" {return DIV;}
"LOAD" {return LOAD;}
"STORE" {return STORE;}
"JMP" {return JMP;}
"CMP" {return CMP;}
"HALT" {return HALT;}
[0-9]+ {return CONST;}
[A-Z]+ {
    return LABEL;
    }
R[0-9]{1} {
        return REGISTER;
}
#[-]?[0-9]+ {    return IMMEDIATE;}
, {return COMMA;}
: {return COLON;}

;[^\n]* {return SEMICOLON;}

[ \t\n] {}
[A-Z]*[a-z]+|[0-9]+[^ \n]*|[a-z][^ \n]* {printf("ERRORS : %s\n",yytext);exit(1);}
. {printf("ERRORS : %s\n",yytext);exit(1);}

%%



int yywrap(){
	return 1;
}
