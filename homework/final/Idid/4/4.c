#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc,char const *argv[])
{
    int rc = fork();

    if(rc<0)
    {
        fprintf(stderr, "fork faild");
        exit(1);
    }
    else if(rc==0)
    {
        char * const argv[] = {"ls","-1","-a","-h",NULL};
        char * const envp[] = {NULL};

        execl("/bin/ls","ls","-l","-a","-h",NULL);
        execlp("ls","ls","-l","-a","-h",NULL);
        execle("/bin/ls","ls","-l","-a","-h",NULL,envp);

        execv("/bin/ls",argv);
        execvp("ls",argv);
        execvpe("ls",argv,envp);
    }
    return 0;
}