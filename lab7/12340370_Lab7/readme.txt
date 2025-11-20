CSL302 Compiler Design Lab 7 
NAME: ASHISH RANJAN
ID: 12340370


FILES INCLUDED: yacc_compile.y , lexical.l , input.txt , Readme.txt

STEPS FOR COMPILING : 
lex lexical.l
yacc -d yacc_compile.y
gcc lex.yy.c y.tab.c -o final 
./final < input.txt


IGNORE THE WARNINGS : Its for the data type char* we have used for reportinng the error 

CODE SUMMARY : we made the tokens required and then returned it  for the for the  yacc where we made stmts and usig optial prefix of labels or optional comments we did it inthe similar fashion. we made different operators for the arithemtics,memory, halting and  conditional. For the yyerror we detected the error and terminated the program there only using exit(1) both in .l and .y files 
In case of successful parsing we printed parsing successful.
