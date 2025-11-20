%{
#include <stdio.h>
char *target=NULL;
%}

%%
[ \t\n]+        { fprintf(yyout,"%s", yytext); }
[a-zA-Z0-9_]+   { if(strcmp(yytext,target)==0){
	fprintf(yyout,"Rannjan ");	
}
else{
fprintf(yyout,"%s", yytext); }
}

.               { fprintf(yyout,"%s", yytext); }
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
	target=argv[2];
    

    yyin = fp;
    yylex();
    fclose(fp);

    return 0;
}

int yywrap() {
    return 1;
}

