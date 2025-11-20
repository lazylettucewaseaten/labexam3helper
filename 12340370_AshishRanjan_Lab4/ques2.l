%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validp = 1;
%}


alpha    [a-zA-Z0-9]
fn        {alpha}+
dn         {alpha}+
ex       (txt|dat)
pdn      \.\.

%%

^.*$    {
    validp = 1;
    char *input=yytext;
    
    if(input[0]!='/') {
        validp=0;
    } else {
        char *pathcp = strdup(input);
        char *sptr;
        char *tkn = strtok_r(pathcp + 1, "/", &sptr); 
        
        for(int k=1;k<strlen(input);k++) {
            if(input[k]=='/' && input[k-1] == '/') {
                validp=0;
                break;
            }
        }
        
        while(tkn!=NULL && validp) {
            int len=strlen(tkn);
            
            if(strcmp(tkn,"..")==0) {
                tkn = strtok_r(NULL,"/",&sptr);
                continue;
            }
            if(len==0){
                validp=0;
                break;
            }
            
            char *dot=strrchr(tkn,'.');
            if(dot!=NULL){
                char *ext=dot+1;
                if(strcmp(ext,"txt")!=0 && strcmp(ext,"dat")!=0) {
                    validp=0;
                    break;
                }
                
                *dot='\0'; 
                if(strlen(tkn)==0) {
                    validp=0;
                    break;
                }
                
                for(int i=0;i<strlen(tkn);i++) {
                    if(!isalnum(tkn[i])){
                        validp=0;
                        break;
                    }
                }
                *dot='.'; 
            } 
            else{
                for(int i=0;i<len;i++){
                    if(!isalnum(tkn[i])){
                        validp=0;
                        break;
                    }
                }
            }
            
            tkn=strtok_r(NULL,"/",&sptr);
        }
        free(pathcp);
    }
    
    if(validp) {
        printf("VALID PATH\n");
    } else {
        printf("INVALID PATH\n");
    }
}

.|\n    { /* ignores */ }

%%

int main() {
    printf("enter paths one per line:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}



