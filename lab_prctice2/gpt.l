%{
#include "y.tab.h"
%}

%%

"("                     { return ROUNDLBRACKET; }
")"                     { return ROUNDRBRACKET; }
"0"                     { return ZERO; }
"1"                     { return ONE; }
[a-zA-Z_][a-zA-Z0-9_]* {
                            if (strcmp(yytext,"if")==0) return IF;
                            else if (strcmp(yytext,"else")==0) return ELSE;
                            else return IDENTIFIER;
                        }
";"                     { return SEMICOLON; }
","                     { return COMMA; }
"-"                     { return MINUS; }
"+"                     { return PLUS; }
"*"                     { return MULT; }
"/"                     { return DIV; }
[ \t\n]+                { /* ignore whitespace */ }

%%

int yywrap() { return 1; }

