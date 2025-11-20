%{
#include<stdio.h>
%}


%%
"#define" {printf("Keyword is %s \n ",yytext);}
"#include" {printf("Keyword is %s \n ",yytext);}
"#ifdef" {printf("Keyword is %s \n ",yytext);}
"#ifndef" {printf("Keyword is %s \n ",yytext);}
"#if" {printf("Keyword is %s \n ",yytext);}
"#else" {printf("Keyword is %s \n ",yytext);}
"#elif" {printf("Keyword is %s \n ",yytext);}
"#endif" {printf("Keyword is %s \n ",yytext);}
"#undef" {printf("Keyword is %s \n ",yytext);}
"#pragma" {printf("Keyword is %s \n ",yytext);}
"#error" {printf("Keyword is %s \n ",yytext);}
"#line" {printf("Keyword is %s \n ",yytext);}

["][^"]*["] {printf("String literal %s\n",yytext);}

[a-zA-Z0-9]+[\.][h]|[a-zA-Z0-9]+[\.][c] {printf("new file is %s\n",yytext);}

[0-9]+|[0-9][xX][A-Fa-f0-9]* {printf("Integer is  %s\n",yytext);}

[0-9]+(\.[0-9]*)?E[+-]?[0-9]+|[0-9]+[\.][0-9]+ {printf("Floating point integer %s\n",yytext);}

[+]|[-]|[*]|[/]|[=][=] {printf("Operatoers is %s\n",yytext);}

@@[^\n]* {printf("Singgle lines  is comments %s\n",yytext);}

$[A-Z][a-zA-Z0-9]* {printf("Identifier is %s\n",yytext);}


"/*"([^*]|\*+[^*/])*\*+"/" {printf("Multiline comments %s\n",yytext);}

\"\"\"([^\"\\]|\\.|\"\")*\"\"\"  { printf("Multiline Comment: %s\n", yytext);}
  
\t|\n {}

. {printf("%s",yytext);}
%%


int main(int argc,char *argv[]){
FILE *fp=fopen(argv[1],"r");
yyin=fp;
	yylex();
	return 0;
	fclose(yyin);
}

int yywrap(){
	return 1;
}
