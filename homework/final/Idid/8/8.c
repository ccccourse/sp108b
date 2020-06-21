#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    char buf;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t rc[2];
    rc[0] = fork();

    if (rc[0]<0)
    {
        fprintf(stderr,"fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if(rc[0]==0)
    {
        close(pipefd[0]);
        char str[]="The first child writes: I'm the first child.";
        write(pipefd[1],str,strlen(str));
        close(pipefd[1]);
        waitpid(rc[1],NULL,0);
    }
    else
    {
        rc[1]=fork();
        if (rc[1]<0)
        {
            fprintf(stderr,"fork faild\n");
            exit(EXIT_FAILURE);
        }
        else if(rc[1] == 0)
        {
            close(pipefd[1]);
            while (read(pipefd[0],&buf,1)>0)
            {
                write(STDOUT_FILENO,&buf,1);
            }
            write(STDOUT_FILENO,"\n",1);
            close(pipefd[0]);
        } 
    }
    return 0;
}