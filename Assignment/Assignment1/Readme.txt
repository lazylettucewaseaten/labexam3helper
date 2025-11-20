CSL302 Assignment 1: Lexical Analyser

Team member 1:   12340370    -   Ashish Ranjan
Team member 2:   12340340    -  Arpit Bhomia


Description (What we did)-
 We first wrote the all the keywords given in the pdf
 Then we match the boolean,integer, double, identifieres 
 Since it was not specifed to show separeate double or seprate double exponention or anything similar, same goes for the hex it comes under the integer
 then we add single line comments, multiline comments.
 For error matching we checked anything starting with  _ , 
 or at the end if anything is no specified by the grammar above, it will say invalid ,
 if a double starts with .
 it says invalid, these corner case were written as the pdf instructed.

Compilation:
lex 12340370_12340340.l
gcc -o 12340370_12340340 lex.yy.c 

Usage: 
12340370_12340340 < [filename]
here wwe used the input.txt;

Files : 
[1.] Readme.txt       - readme instruction file 
[2.] 12340370_12340340.l          - main mlex file
[3.] 12340370_12340340          - executable file after compiling
[4.] lex.yy.c         - c file generated after compiling lexer.l
[5.] input.txt   - sample input for checking


Refrences: 
[1.] Took help from previously submitted lab assignemnt 
[2.] Flex Documentation: https://westes.github.io/flex/ 