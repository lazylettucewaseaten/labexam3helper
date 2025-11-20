%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

extern void yyerror(const char *);
%}

%%

"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
">"             { return GT; }
"int"           { return INT; }
"float"         { return FLOAT; }
"true"          { return TRUE; }
"false"         { return FALSE; }
"not"           { return NOT; }
"and"           { return AND; }
"or"            { return OR; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return ID; }
[0-9]+                  { yylval.num = atoi(yytext); return NUM; }
[0-9]+\.[0-9]+          { yylval.fnum = atof(yytext); return FNUM; }


"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"="             { return '='; }
"("             { return '('; }
")"             { return ')'; }
";"             { return ';'; }
","             { return ','; }

[ \t\n]+        { }

.               { yyerror("Unknown character"); }

%%

int yywrap() {
    return 1;
}
