/* ========== LEXER (lexer.l) ========== */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern int yylineno;
%}

%option yylineno

%%

"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
"void"          { return VOID; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"return"        { return RETURN; }
"main"          { return MAIN; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return ID; }
[0-9]+                  { yylval.str = strdup(yytext); return NUM; }
[0-9]+\.[0-9]+          { yylval.str = strdup(yytext); return FNUM; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACK; }
"]"             { return RBRACK; }
";"             { return SEMI; }
","             { return COMMA; }

[ \t\r]+        { /* ignore whitespace */ }
\n              { /* ignore newlines */ }
"//"[^\n]*      { /* single line comment */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* multi-line comment */ }

.               { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}