ASISIGNMENT 1 ASP

For this assignment, I have created 3 C programs namely:-
1> Mapper.c
2>Reducer.c
3>Combiner.c

Mapper.c
This program read input from a text file ('File.txt' in this case) from the same directory in which the program exist. 
The input will be each string line from the text file till it reaches EOF and prints in the console output in the format (WordName,1).
Here WordName is the value of each string from input.

Reducer.c

This program reads from the console screen to maintain the count index of each word entered through the input. 
To achieve the same I have created a data structure(Linked List) to store the value of count and wordname of each word encountered as
node. For each new word, the program will 1st check if the 1st character of the input word is matching with the 1st character of the
head node.If its matching it will procees till the end of the list or till the input word entirely matches with the node word value. 
In case the value of the new input word matches with the node word value, it will increase the count by 1 else if it's not matching, 
the list will create a new node with the wordvalue as new word and set the count as 1 and append it to the end of the list. 
If the 1st character doesnt match with the new input word, then the program print all the elements along with its count present in the 
list and insert a new node with the value of encountered input value and count as 1 and make this node as the Head node of the list. 
This process will continue till it recieved input as EOF from console.

Combiner.c

This program acts as parent program for above both programs. I am making a pipe system call to create a communication mode between the 
above two programs. Once the communication mode is setup I am creating a child process of this program by using a fork system call.
Now inside the child process we are connecting the write end of the pipe with Console output by using dup2 system call. After that we 
are replacing the memory address of the program to the memory address of the Mapper program through excelp system call.
In the parent process we are creating another child and inside that child process we are connecting the read end of the pipe with the 
console input by the dup2 call. Then we are replacing this process with Reducer one by using excelp system call. Thus the output of the mapper program will act as input for reducer program. 
We are exiting from the parent process when the both the child process terminates.

Instruction To execute
1> Type 'make' in terminal from the directory where programs are extracted and press enter.
2> Type './combiner' and press enter.
