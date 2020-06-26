# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main(int argc,char *argv[])
{
    int x = 100;
    int rc = fork();
    if(rc<0)
    {
        fprintf(stderr,"fork faild\n");
        exit(1);
    }
    else if(rc == 0)
    {
        x = 99;
        printf("x in child process: %d (pid:%d)\n",x,(int) getpid());
    }
    else
    {
        x = 101;
        printf("x in parent process: %d (pid:%d)\n",x,(int) getpid());
    }
    return 0;
}
