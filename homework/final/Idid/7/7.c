#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t rc = fork();
    if(rc<0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc==0)
    {
        close(STDOUT_FILENO);
        printf("child calls print().");
    }
    /*else
    {
        printf("this is parent");
    }*/
    return 0;
}