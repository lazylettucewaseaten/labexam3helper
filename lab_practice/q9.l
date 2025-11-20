%{
#include<stdio.h>
%}

NAME [a-zA-Z0-9]+
EXT  \.(txt|dat)
DOTDOT \.\.
VALID \/(({NAME}|{DOTDOT})\/)*({NAME}({EXT})?)\/? 

%%
{VALID} {printf("VALID PATH\n");}
.+ {printf("INVALID PATH\n");}
%%

int main(){
	yylex();
	return 0;
}
int yywrap(){
	printf("Invalid PAth\n");
return 1;
}
