//REMOVE COMMENTS
%{
#include <stdio.h>
%}

%%
"//".*              { /* Skip single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"   { /* Skip multi-line comments */ }
.                   { putchar(yytext[0]); }
\n                  { putchar('\n'); }
%%

int main() {
    yylex();
    return 0;
}


//MINI SQL RECOGNIZER
%{
#include <stdio.h>
%}

IDENT    [a-zA-Z_][a-zA-Z0-9_]*
NUMBER   [0-9]+

%%
"SELECT"     { printf("TOKEN: SELECT\n"); }
"FROM"       { printf("TOKEN: FROM\n"); }
"WHERE"      { printf("TOKEN: WHERE\n"); }
","          { printf("TOKEN: COMMA\n"); }
";"          { printf("TOKEN: SEMICOLON\n"); }
{IDENT}      { printf("TOKEN: IDENTIFIER (%s)\n", yytext); }
{NUMBER}     { printf("TOKEN: NUMBER (%s)\n", yytext); }
">"|"<"|"="  { printf("TOKEN: OPERATOR (%s)\n", yytext); }
[ \t\n]+     { /* skip whitespace */ }
.            { printf("UNKNOWN: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}


//HTML RECOGNIZER
%{
#include <stdio.h>
%}

TAG      "<"[a-zA-Z][a-zA-Z0-9]*">"
ENDTAG   "</"[a-zA-Z][a-zA-Z0-9]*">"
ATTR     [a-zA-Z][a-zA-Z0-9]*"="[\"'][^\"']*[\"']

%%
{TAG}        { printf("TOKEN: TAG (%s)\n", yytext); }
{ENDTAG}     { printf("TOKEN: ENDTAG (%s)\n", yytext); }
{ATTR}       { printf("TOKEN: ATTRIBUTE (%s)\n", yytext); }
[^<> \t\n]+  { printf("TOKEN: TEXT (%s)\n", yytext); }
[ \t\n]+     { /* skip whitespace */ }
.            { /* ignore other characters */ }
%%

int main() {
    yylex();
    return 0;
}


//GREP
%{
#include <stdio.h>
#include <string.h>

char pattern[100];

%}

%%
.*\n   {
          if (strstr(yytext, pattern))
              printf("%s", yytext);
       }
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.out pattern < file\n");
        return 1;
    }
    strcpy(pattern, argv[1]);
    yylex();
    return 0;
}

//LS
%{
#include <stdio.h>
#include <dirent.h>
%}

%%
.|\n   { /* ignore input, just trigger directory scan */ }
%%

int main() {
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL) {
        perror("opendir");
        return 1;
    }
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }
    closedir(dr);
    return 0;
}

//CUT for CSV
%{
#include <stdio.h>
#include <string.h>

int column = 1;
%}

%%
.*\n  {
         char line[1000];
         strcpy(line, yytext);
         char *tok = strtok(line, " \t");
         int col = 1;
         while (tok) {
             if (col == column) {
                 printf("%s\n", tok);
                 break;
             }
             tok = strtok(NULL, " \t");
             col++;
         }
      }
%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.out column < file\n");
        return 1;
    }
    column = atoi(argv[1]);
    yylex();
    return 0;
}
//SORTING LEXIOGRAPHICALLY
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lines[1000];
int count = 0;

%}

%%
.*\n  {
         lines[count] = strdup(yytext);
         count++;
      }
%%

int cmpfunc(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    yylex();
    qsort(lines, count, sizeof(char *), cmpfunc);
    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
    }
    return 0;
}

//UNIQ REMOVE DUPLICATES
%{
#include <stdio.h>
#include <string.h>

char prev[1000] = "";
%}

%%
.*\n   {
          if (strcmp(prev, yytext) != 0) {
              printf("%s", yytext);
              strcpy(prev, yytext);
          }
       }
%%

int main() {
    yylex();
    return 0;
}

//REVERSE EACH WORD
%{
#include <stdio.h>
#include <string.h>

// Function to reverse a string in-place
void reverse(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n/2; i++) {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }
}
%}

%%
[a-zA-Z]+   {   // Match words
                char word[1000];
                strcpy(word, yytext);
                reverse(word);
                printf("%s", word);
            }
[ \t\n]+    { printf("%s", yytext); }   // Keep spaces/newlines as is
.           { printf("%s", yytext); }    // Print other characters unchanged
%%

int main() {
    yylex();
    return 0;
}

//COUNTIING
%{
#include <stdio.h>
int vowels=0, consonants=0, digits=0, spaces=0;
%}

%%
[aeiouAEIOU]  { vowels++; }
[a-zA-Z]      { consonants++; }
[0-9]         { digits++; }
[ \t\n]       { spaces++; }
.             { }
%%

int main() {
    yylex();
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpaces: %d\n", vowels, consonants, digits, spaces);
    return 0;
}


//PALINDROME 
%{
#include <stdio.h>
#include <string.h>

int isPalindrome(char *s) {
    int n = strlen(s);
    for (int i=0; i<n/2; i++)
        if (s[i] != s[n-1-i]) return 0;
    return 1;
}
%}

%%
[a-zA-Z]+   { if (isPalindrome(yytext)) printf("%s : Palindrome\n", yytext);
              else printf("%s : Not Palindrome\n", yytext); }
[ \t\n]+    { }
.           { }
%%

int main() { yylex(); return 0; }


//REPLACE
%{
#include <stdio.h>
%}

%%
"cat"   { printf("dog"); }
.|\n    { printf("%s", yytext); }
%%

int main() { yylex(); return 0; }
//WORD FREQUENCY 
%{
#include <stdio.h>
#include <string.h>

struct Word { char w[50]; int c; } dict[1000];
int n=0;

void addWord(char *s) {
    for (int i=0; i<n; i++)
        if (strcmp(dict[i].w, s)==0) { dict[i].c++; return; }
    strcpy(dict[n].w, s);
    dict[n].c = 1;
    n++;
}
%}

%%
[a-zA-Z]+   { addWord(yytext); }
[ \t\n]+    { }
.           { }
%%

int main() {
    yylex();
    for (int i=0; i<n; i++)
        printf("%s : %d\n", dict[i].w, dict[i].c);
    return 0;
}

//ANAGRAM
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char word1[100], word2[100];
int count=0;

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}
%}

%%
[a-zA-Z]+   {
                if (count==0) strcpy(word1, yytext);
                else if (count==1) strcpy(word2, yytext);
                count++;
            }
[ \t\n]+    { }
.           { }
%%

int main() {
    yylex();
    if (count==2) {
        qsort(word1, strlen(word1), sizeof(char), cmp);
        qsort(word2, strlen(word2), sizeof(char), cmp);
        if (strcmp(word1, word2)==0) printf("Anagram\n");
        else printf("Not Anagram\n");
    } else {
        printf("Please enter two words!\n");
    }
    return 0;
}

//LONGEST WORD
%{
#include <stdio.h>
#include <string.h>
char longest[100]="";
%}

%%
[a-zA-Z]+   {
                if (strlen(yytext) > strlen(longest))
                    strcpy(longest, yytext);
            }
[ \t\n]+    { }
.           { }
%%

int main() {
    yylex();
    printf("Longest word: %s\n", longest);
    return 0;
}


//CHARACTER HISTOGRAM
%{
#include <stdio.h>
int freq[256] = {0};
%}

%%
.|\n   { freq[yytext[0]]++; }
%%

int main() {
    yylex();
    for (int i=0; i<256; i++) {
        if (freq[i] > 0)
            printf("%c : %d\n", i, freq[i]);
    }
    return 0;
}

//DUPLICATE WORD REMOVER
%{
#include <stdio.h>
#include <string.h>

char prev[100]="";
%}

%%
[a-zA-Z]+   {
                if (strcmp(prev, yytext)!=0) {
                    printf("%s ", yytext);
                    strcpy(prev, yytext);
                }
            }
[ \t\n]+    { }
.           { }
%%

int main() { yylex(); return 0; }

//LCS
%{
#include <stdio.h>
#include <string.h>

char str1[1000], str2[1000];
int count = 0;

int max(int a, int b) { return (a > b) ? a : b; }

void findLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];

    // Build LCS length table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Reconstruct the LCS string
    int index = dp[m][n];
    char lcs[index+1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("Length: %d\n", dp[m][n]);
}
%}

%%
[a-zA-Z0-9]+   {
                   if (count == 0) strcpy(str1, yytext);
                   else if (count == 1) strcpy(str2, yytext);
                   count++;
               }
[ \t\n]+       { }
.              { }
%%

int main() {
    yylex();
    if (count == 2) {
        findLCS(str1, str2);
    } else {
        printf("Please provide two words/strings!\n");
    }
    return 0;
}


//COLUMN EXTRACTOR
%{
#include <stdio.h>
#include <string.h>
int col=1;
%}

%%
.*\n  {
    char line[1000];
    strcpy(line, yytext);
    char *tok=strtok(line,",");
    int c=1;
    while(tok){
        if(c==col) printf("%s\n",tok);
        tok=strtok(NULL,",");
        c++;
    }
}
%%

int main(int argc,char *argv[]){
    if(argc<2){printf("Usage: ./a.out col < file.csv\n");return 1;}
    col=atoi(argv[1]);
    yylex();
    return 0;
}

//COUNT ROWS AND COLUMNS
%{
#include <stdio.h>
int rows=0, maxcols=0;
%}

%%
.*\n {
    rows++;
    int cols=1;
    for(int i=0;yytext[i];i++) if(yytext[i]==',') cols++;
    if(cols>maxcols) maxcols=cols;
}
%%

int main(){
    yylex();
    printf("Rows: %d\nColumns (max): %d\n",rows,maxcols);
    return 0;
}

//SKIP HEADER
%{
#include <stdio.h>
int first=1;
%}

%%
.*\n {
    if(first){first=0;}
    else printf("%s",yytext);
}
%%

int main(){ yylex(); return 0; }


//FIND MAX MIN
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int col=1, first=1, minv, maxv;
%}

%%
.*\n {
    char line[1000]; strcpy(line,yytext);
    char *tok=strtok(line,",");
    int c=1;
    while(tok){
        if(c==col){
            int v=atoi(tok);
            if(first){minv=maxv=v; first=0;}
            else{ if(v<minv)minv=v; if(v>maxv)maxv=v;}
        }
        tok=strtok(NULL,",");
        c++;
    }
}
%%

int main(int argc,char *argv[]){
    if(argc<2){printf("Usage: ./a.out col < file.csv\n");return 1;}
    col=atoi(argv[1]);
    yylex();
    printf("Min=%d, Max=%d\n",minv,maxv);
    return 0;
}

    //ROWS wher MSRKS>N

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int col=1, limit=0;
%}

%%
.*\n {
    char line[1000]; strcpy(line,yytext);
    char *tok=strtok(line,",");
    int c=1;
    while(tok){
        if(c==col && atoi(tok)>limit)
            printf("%s",yytext);
        tok=strtok(NULL,","); c++;
    }
}
%%

int main(int argc,char *argv[]){
    if(argc<3){printf("Usage: ./a.out col limit < file.csv\n");return 1;}
    col=atoi(argv[1]); limit=atoi(argv[2]);
    yylex(); return 0;
}

//VALIDATE CSV
%{
#include <stdio.h>
int expected=-1, row=0;
%}

%%
.*\n {
    row++;
    int cols=1;
    for(int i=0;yytext[i];i++) if(yytext[i]==',') cols++;
    if(expected==-1) expected=cols;
    else if(cols!=expected) printf("Row %d has %d cols (expected %d)\n",row,cols,expected);
}
%%

int main(){ yylex(); return 0; }

//COLUMN SUM AVERAGE
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int col=1, sum=0, count=0;
%}

%%
.*\n {
    char line[1000]; strcpy(line,yytext);
    char *tok=strtok(line,",");
    int c=1;
    while(tok){
        if(c==col){ sum+=atoi(tok); count++; }
        tok=strtok(NULL,","); c++;
    }
}
%%

int main(int argc,char *argv[]){
    if(argc<2){printf("Usage: ./a.out col < file.csv\n");return 1;}
    col=atoi(argv[1]);
    yylex();
    printf("Sum=%d Avg=%.2f\n",sum,(count?(double)sum/count:0));
    return 0;
}

//SORT CSV BY COLUMN
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *lines[1000]; int count=0, col=1;

int cmp(const void *a,const void *b){
    char *la=*(char**)a, *lb=*(char**)b;
    char ca[100], cb[100]; strcpy(ca,la); strcpy(cb,lb);
    char *t1=strtok(ca,","),*t2=strtok(cb,","); int c=1;
    while(t1 && c<col){t1=strtok(NULL,",");c++;}
    c=1; while(t2 && c<col){t2=strtok(NULL,",");c++;}
    return atoi(t1)-atoi(t2);
}
%}

%%
.*\n { lines[count]=strdup(yytext); count++; }
%%

int main(int argc,char *argv[]){
    if(argc<2){printf("Usage: ./a.out col < file.csv\n");return 1;}
    col=atoi(argv[1]);
    yylex();
    qsort(lines,count,sizeof(char*),cmp);
    for(int i=0;i<count;i++) printf("%s",lines[i]);
    return 0;
}

//JOINGN CSV 
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Row {char id[100]; char data[1000];} A[1000];
int n=0;
%}

file1 [^:]*

%%
%%

int main(int argc,char *argv[]){
    if(argc<3){printf("Usage: ./a.out f1 f2\n");return 1;}
    FILE *f=fopen(argv[1],"r"); char line[1000];
    while(fgets(line,1000,f)){
        char *id=strtok(line,",");
        strcpy(A[n].id,id); strcpy(A[n].data,line); n++;
    }
    fclose(f);

    f=fopen(argv[2],"r");
    while(fgets(line,1000,f)){
        char *id=strtok(line,",");
        for(int i=0;i<n;i++) if(strcmp(A[i].id,id)==0){
            printf("%s,%s",A[i].data,strtok(NULL,"\n"));
        }
    }
    fclose(f);
    return 0;
}


//REMOVE DUPLICATE ROW
%{
#include <stdio.h>
#include <string.h>
char prev[1000]="";
%}

%%
.*\n {
    if(strcmp(prev,yytext)!=0){
        printf("%s",yytext);
        strcpy(prev,yytext);
    }
}
%%

int main(){ yylex(); return 0; }
//TRANSPOSE CSV
%{
#include <stdio.h>
#include <string.h>
char table[1000][1000][100]; int rows=0, cols=0;
%}

%%
.*\n {
    char line[1000]; strcpy(line,yytext);
    char *tok=strtok(line,","); int c=0;
    while(tok){ strcpy(table[rows][c],tok); tok=strtok(NULL,","); c++; }
    if(c>cols) cols=c;
    rows++;
}
%%

int main(){
    yylex();
    for(int j=0;j<cols;j++){
        for(int i=0;i<rows;i++){
            if(i>0) printf(",");
            printf("%s",table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//Extract IP+Request 
%{
#include <stdio.h>
%}

%%
[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+  { printf("IP: %s\n",yytext); }
\"(GET|POST|PUT|DELETE)[^\"]*\" { printf("REQ: %s\n",yytext); }
.|\n                            { }
%%

int main(){ yylex(); return 0; }

//INSerting line at specifi postion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp, *temp;
    char filename[50], newline[200], buffer[200];
    int line_no, count = 1;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) { printf("File not found!\n"); return 1; }

    temp = fopen("temp.txt", "w");
    if (!temp) { printf("Temp file error!\n"); return 1; }

    printf("Enter line number to insert at: ");
    scanf("%d", &line_no);
    getchar(); // consume leftover newline
    printf("Enter new line: ");
    fgets(newline, sizeof(newline), stdin);

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (count == line_no)
            fputs(newline, temp);
        fputs(buffer, temp);
        count++;
    }

    // If line number is after EOF, append it
    if (line_no >= count) fputs(newline, temp);

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);

    printf("Line inserted successfully!\n");
    return 0;
}

//KEY VALUE MAP
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Map {
    char key[50];
    char value[50];
};

struct Map dict[MAX];
int count = 0;

// Insert key,value
void insert(char *k, char *v) {
    strcpy(dict[count].key, k);
    strcpy(dict[count].value, v);
    count++;
}

// Find value by key
char* find(char *k) {
    for (int i = 0; i < count; i++) {
        if (strcmp(dict[i].key, k) == 0)
            return dict[i].value;
    }
    return NULL; // not found
}

int main() {
    // Insert some pairs
    insert("cat", "dog");
    insert("apple", "fruit");
    insert("red", "color");

    // User query
    char key[50];
    printf("Enter key: ");
    scanf("%s", key);

    char *result = find(key);
    if (result)
        printf("Found: %s -> %s\n", key, result);
    else
        printf("Key not found!\n");

    return 0;
}


//STRTOK
#include <stdio.h>
#include <string.h>

int main() {
    char line[] = "cat,dog,apple,fruit";
    char *token;

    token = strtok(line, ",");  // split by comma
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");  // continue splitting
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "This is a test string";
    char *token = strtok(str, " ");  // split by space

    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, " ");  // continue with NULL
    }
    return 0;
}

//STORING INTO ARRAY OF STRINGS
#include <stdio.h>
#include <string.h>

int main() {
    char line[] = "cat dog apple mango";
    char *token;
    char tokens[10][50];  // array of strings (max 10 words, each max 50 chars)
    int count = 0;

    token = strtok(line, " ");  // split by space
    while (token != NULL) {
        strcpy(tokens[count], token);  // copy token into array
        count++;
        token = strtok(NULL, " ");     // get next token
    }

    // Print stored tokens
    printf("Stored tokens:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i, tokens[i]);
    }

    return 0;
}


//WC
%{

	#include<stdio.h>
	int word=0,tchar=0,line=0; 
%}

%%

\n {line++;tchar++;}
[ \t]+ {tchar+=yyleng;}
[^ \t\n]+ {word++;tchar+=yyleng;}

%%



int yywrap(){
	return 1;
}

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Enter the file name also\n");
		return 0;
	}
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	printf("%d %d %d %s\n",line,word,tchar,argv[1]);	
	fclose(yyin);
	return 0;
}

//DIR MATCHING
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


//VARIABLE THING
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


//COMMENTS


\/\*([^*]|\*+[^*\/])*\*+\/      { printf("C style multiline comment\n"); }
\"\"\"([^\\]|\\.|\\\n)*\"\"\"   { printf("Python style multiline comment\n"); }
'''([^\\]|\\.|\\\n)*'''   { printf("Python style multiline comment\n"); }
--\[\[([^]]|\]+[^\]])*\]+]]    { printf("Lua comment\n"); }
\{[^}]*\}                      { printf("Pascal comment\n"); }
\(\*([^*]|\*+[^)])*\*+\)       { printf("Pascal comment\n"); }



//GENERAL GUIDELINES
“whatever” when i want to match something like hardcoded we can write inside the whatever [(] or we can use “(” 

I want to match  “.” can do it with \. Or  “.”

[ \t]+ [\t]  the second one only matches the \t but the first one matches both \t and a space

To match “ use with escape character \ 

Can i write so that it will be greater than a specific thing 

What happens next?
This is where backtracking comes in.
The regex engine realizes: the final part \*+/ must match */.


But the middle part consumed all the * characters.


So it backs up: it "gives back" (unmatches) one or more * from the middle part.


Now the middle part matches fewer *s, leaving at least one * before the final /.


The final part then matches those remaining * plus the /.
Multiline comments 
“/*”([^*]|\*+[^*/])*\*+”/”  /* … */
“”” … ‘’’’ 
\"\"\"([^\"\\]|\\.|\"\")*\"\"\"  for the it wil give error with “ in the between with two it works fine

yyterminate(); to close lexiacla analysis

FILE *yyin,*yyout; 

. {fprintf(yyout,"%s",yytext);} so that wer can printf directly in the yyout which will be the pointer of the writing file 

FILE *fp=fopen(argv[1],"r");
	FILE *fp2=fopen(argv[2],"w");
	yyin=fp;
	yyout=fp2;


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




\"{3,4}([^\n]*\n){0,4}[^\n]*\"{3,4} {
    printf("Valid multiline comment (<=5 lines)\n");
}



\/\*([^*]|\*+[^*\/])*\*+\/      { printf("C style multiline comment\n"); }
\"\"\"([^\\]|\\.|\\\n)*\"\"\"   { printf("Python style multiline comment\n"); }
'''([^\\]|\\.|\\\n)*'''   { printf("Python style multiline comment\n"); }
--\[\[([^]]|\]+[^\]])*\]+]]    { printf("Lua comment\n"); }
\{[^}]*\}                      { printf("Pascal comment\n"); }
\(\*([^*]|\*+[^)])*\*+\)       { printf("Pascal comment\n"); }


%%
[ \t\n]+        { fprintf(yyout,"%s", yytext); }
"ashish" {fprintf(yyout,"Ranjan ");}
[a-zA-Z0-9_]+   { fprintf(yyout,"%s", yytext); }
.               { fprintf(yyout,"%s", yytext); }
%%


