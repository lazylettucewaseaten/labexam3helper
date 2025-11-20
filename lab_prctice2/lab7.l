%{
#include<stdio.h>
#include "y.tab.h"
extern int yylineno;
%}

%%

"MOV" {return MOV;}
"ADD" {return ADD;}
"SUB" {return SUB;}
"MUL" {return MUL;}
"DIV" {return DIV;}
"LOAD" {return LOAD;}
"JMP" {return JMP;}

"HALT" {return HALT;}
"STORE" {return STORE;}
[0-9]+ {return CONST;}
[A-Z]+ {return LABEL;}
[R][0-9] {return REGISTER;}
#[-]?[0-9]+ {return IMMEDIATE;}
, {return COMMA;}
: {return COLON;}

;[^\n]* {return SEMICOLON;}

[ \t\n] {}
. {}


%%


int yywrap(){
    return 1;
}


