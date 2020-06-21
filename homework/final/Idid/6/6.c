#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc ,char *argv[])
{
    int wstatus;
    int rc = fork();
    if(rc<0)
    {
        fprintf(stderr,"fork failed");
        exit(1);
    }
    else if(rc==0)
    {
        int waitpid_return = waitpid(-1,NULL,WUNTRACED | WCONTINUED);
        printf("child wait return: %d\n",waitpid_return);
    }
    else
    {
        int waitpid_return = waitpid(rc,&wstatus,WUNTRACED | WCONTINUED);
        printf("parent wait return: %d\n",waitpid_return);
        printf("if the child terminated normally: %s\n",WIFEXITED(wstatus) ? "true" : "false");
    }
    return 0;
}