%{
#include<stdio.h>
%}

%%
"foreach" {printf("Keyword found :  %s",yytext);}
"echo" {printf("Keyword found :  %s",yytext);}
"read" {printf("Keyword found : %s",yytext);}
_([a-z])*[0-9]* {printf("Identifier found : %s",yytext);}

%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}

