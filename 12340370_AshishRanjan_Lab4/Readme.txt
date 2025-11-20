ASHISH RANJAN
12340370
LAB4 (Lexical Analysis)
Part (1.)
1.)
head.l  is the lex file and the .head  is the executable which prints  the top 10 lines at max of the file.

2.)
tail.l is the lex file and .tail is the executable which prints the  bottom 10 lines at max of the file.

3.)
cat.l is the lex file and .cat is the executable  which prints all the char of the file.

These three commands are used as:
./[exec_name] < [file_name]

4.)
cp.l is the lex file and cp is the executable which copies the content oof the first argument into second argumnet

This is used as:
./[exec_name] [source] [dest]

The output1 is the output we got  when we used  the ./cp tail.l output1 

Part 2.)

For matching the directories and the file,
we have  use strtok_r,strcmp and strrchr as external function for our help where we split the words on the basis of the / or .  and check 

The file is ques2.l and the executalbe is  ./ques2

This command is used as
./[execname] 


Then enter paths like:
/home/ashiishuser/temp.txt
home//file.txt
/invalid@ispath/file.txt



Lex Files:
head.l
tail.l
cat.l
cp.l
ques2.l

Executalbe:
head
tail
cat
cp
ques2

Misc/Other Files
output1
lex.yy.c
Readme.txt
