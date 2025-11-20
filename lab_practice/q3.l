%{
#include<stdio.h>
int word=0,space=0,newlines=0;
%}


%%
\n  { newlines++;word+=yyleng;}
[ \t]+	 {word+=yyleng;}
[^ \t\n]+ {space++;word+=yyleng;}
%%


int main(int argc,char * argv[]){
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	printf("words is  %d\n",space);
	printf("characters is  %d\n",word);
	printf("total lines is %d\n",newlines);
	fclose(fp);
	return 0;
}

int yywrap(){
	return 1;
}
