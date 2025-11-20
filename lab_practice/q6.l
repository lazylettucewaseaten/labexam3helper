%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
int t1=0;
%}

%%
\n {if(t1){
	count--;
}
else{
count++;
}
if(count<10 && t1){
printf("%s",yytext);
}
}

. {if(t1 && count<10){
	printf("%s",yytext);
}}


%%

int main(int argc,char* argv[]){
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	rewind(yyin);
	t1=1;
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
