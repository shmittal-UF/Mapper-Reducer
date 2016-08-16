#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
  {
     pid_t pid;
     int fd[2],status;
     if(pipe(fd)<0)
      exit(0);
    
     if ((pid = fork()) == -1)
        perror("fork error");
     else if (pid == 0) {
       close(fd[0]);
       dup2(fd[1],STDOUT_FILENO);
       close(fd[1]);
       execlp("./mapper","./mapper",NULL);
       printf("\n Fails to Execute");
       }
     else
      { 
       pid_t pid1;
       if ((pid = fork()) == -1)
        perror("fork error");
       else if (pid == 0)
       {     
       close(fd[1]);
       dup2(fd[0],STDIN_FILENO);
       close(fd[0]);
       execlp("./reducer","./reducer",NULL);
       }
       else {
       close(fd[0]);
       close(fd[1]);
        while((pid=wait(&status))!=-1);
        }
       }
     }
  
