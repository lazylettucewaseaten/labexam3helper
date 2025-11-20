%{
#include<stdio.h>
int count=0;
%}

%%
\n {count++;printf("%s",yytext);if(count==10){
	yyterminate();
}}
. {printf("%s",yytext);}
%%


int main(int argc,char* argv[]){
	
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	fclose(yyin);
	return 0;
}

int yywrap(){
	return 1;
}
