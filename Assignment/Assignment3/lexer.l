%{
#include<stdio.h>
#include "y.tab.h"
extern int yylineno;
%}

%%
"void"           { return VOID; }
"int"            { return INT; }
"bool"           { return BOOL; }
"string"         { return STRING; }
"for"            { return FOR; }
"while"          { return WHILE; }
"do"             { return DO;}
"class"          { return CLASS; }
"true"           {return TRUELIT;}
"false"           {return FALSELIT;}
"if"             { return IF; }
"else"           { return ELSE; }
"return"         { return RETURN; }
"break"          { return BREAK; }
"New"            { return NEW; }
"NewArray"       { return NEWARRAY; }
"main"           { return MAIN; }

[-]?[0-9]+ { yylval.num = atoi(yytext); return NUMBER; }
[0-9]+"."[0-9]+ { yylval.fnum = atof(yytext); return FNUMBER; }

[a-zA-Z][a-zA-Z0-9_]*      {if(strlen(yytext)<=31) {yylval.str = strdup(yytext); return IDENTIFIER;}
    else{
        printf("Too long identifier not permitted more than 31 %s\n",yytext);
    }
    }


[_][a-zA-Z0-9_]* {printf("(%s) this is not a valid identifier \n", yytext);} 

"+" { return '+'; }
"-" { return '-'; }
"*" { return '*'; }
"/" { return '/'; }

"=="                {return EQ;}
"!"                 {return NOT;}
"<"                 {return LT;}
">"                 {return GT;}
">="                {return GE;}
"<="                {return LE;}
"!="                {return NE;}
"&&"                {return AND;}
"="                 {return ASSIGNMENT;}
"||"                {return OR;}
";"                  {return SEMICOLON;}
","                    {return COMMA;}
"("             {return ROUNDLBRACKET;}
")"             {return ROUNDRBRACKET;}
"{"             {return CURLYLBRACKET;}
"}"             {return CURLYRBRACKET;}
"."     {return DOT;}
"["     {return SQUARELBRACKET;}
"]"     {return SQUARERBRACKET;}
"//"[^\n]* {}
[ \n\t]+ {}
"/*"([^*]|\*+[^*/])*\*+"/"  { }
   
%%

int yywrap(){
    return 1;
}

//our assignment made by bhomia and ranjan
