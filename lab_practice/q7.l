%{
#include<stdio.h>
%}


%%
. {printf("%s",yytext);}

%%

int main(int argc,char * argv[]){
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
