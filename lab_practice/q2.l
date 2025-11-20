%{
#include<stdio.h>
%}

%%
\"A\" {printf("matched soething %s\n",yytext);}
[A-Z][a-z]*[" "][A-Z][a-z]* {printf("Name is %s\n",yytext);}
["("][0-9]{3}")"[" "][0-9]{3}"-"[0-9]{4} {printf("Phone No. is  %s\n",yytext);}
[a-zA-Z][a-zA-Z0-9]*"@"[a-z]*"."[a-z]*[\.][a-z]* {printf("Email  is %s\n",yytext); }
[0-9]{4}[0-9]{4}[0-9]{4}[0-9]{4} {printf("Credit Card Info is %s\n",yytext);}
.|\n {}

%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
