%{
#include<stdio.h>
#include<stdlib.h>
FILE *yyin,*yyout;
%}

%%
. {fprintf(yyout,"%s",yytext);}

%%

int main(int argc,char * argv[]){
	FILE *fp=fopen(argv[1],"r");
	FILE *fp2=fopen(argv[2],"w");
	yyin=fp;
	yyout=fp2;
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
