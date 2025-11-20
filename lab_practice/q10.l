%{
#include<stdio.h>
char *str[1024];
int line=0;
%}



%%
\/\*([^*]|\*+[^*\/])*\*+\/      { printf("C style multiline comment\n"); }
\"\"\"([^\\]|\\.|\\\n)*\"\"\"   { printf("Python style multiline comment\n"); }
'''([^\\]|\\.|\\\n)*'''   { printf("Python style multiline comment\n"); }
--\[\[([^]]|\]+[^\]])*\]+]]    { printf("Lua comment\n"); }
\{[^}]*\}                      { printf("Pascal comment\n"); }
\(\*([^*]|\*+[^)])*\*+\)       { printf("Pascal comment\n"); }

[^\n]* {str[line]=strdup(yytext);line++;}
\n {str[line]=strdup(yytext);line++;}

%%

int main(int argc,char *argv[]){
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	line--;
	for(int i=line;i>=0;i--){
		printf("%s",str[i]);
	}
	return 0;
}

int yywrap(){
	return 1;
}
