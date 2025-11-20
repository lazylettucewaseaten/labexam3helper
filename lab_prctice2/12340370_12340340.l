%{
#include<stdio.h>
#include "y.tab.h"
extern int yylineno;
%}

%%
"void"           { return VOID; }
"int"            { return INT; }
"double"         { return DOUBLE; }
"bool"           { return BOOL; }
"string"         { return STRING; }
"for"            { return FOR; }
"while"          { return WHILE; }
"do"             { return DO;}
"class"          { return CLASS; }
"then" {return THEN;}
"elif" {return ELIF;}
"switch" {return SWITCH;}
"case" {return CASE;} 
"if"             { return IF; }
"else"           { return ELSE; }
"return"         { return RETURN; }

"break"          { return BREAK; }
"New"            { return NEW; }
"NewArray"       { return NEWARRAY; }
"main"           { return MAIN; }
[0] {return ZERO;}
[1] {return ONE;}
"fact" {return FACT;}

[0-9]+|0[xX][a-fA-F0-9]+|[0-9]+[.][0-9]+ {return NUMBER;}

 

\.[0-9]+([Ee][-+]?[0-9]+)? {printf("(%s) is not a valid double as there should be a number before the dot\n", yytext);} 



[a-zA-Z][a-zA-Z0-9_]*      {if(strlen(yytext)<=31) return IDENTIFIER;
    else{
        printf("Too long identifier not permitted more than 31 %s\n",yytext);
    }
    }


[_][a-zA-Z0-9_]* {printf("(%s) this is not a valid identifier \n", yytext);} 

\"[^\n\"]*\" {return STRING_LITERAL;}
"!"|"unary -"       {return UNARY;}
"*"|"/"|"%"         {return MULTIPLITIVE;}
"+"|"-"             {return ADDITIVE;}
"<="|">="|"<"|">"   {return RELATIONAL;}
"=="|"!="           {return EQUALITY;}
"&&"                {return AND;}
"="                 {return ASSIGNMENT;}
"||"                {return OR;}
";"                  {return SEMICOLON;}
","                    {return COMMA;}
":"			{return COLON;}
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
