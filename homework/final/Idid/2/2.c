#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int 
main(int argc, char*argv[])
{
    int rc = fork();
    int fd = open("./2.txt",O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    write(fd, "First line.\n",strlen("First line.\n"));

    if(rc<0)
    {
        fprintf(stderr,"fork faild\n");
        exit(1);
    } 
    else if(rc==0)
    {
        write(fd,"child writes a line.\n",strlen("child writes a line."));
        printf("file descriptor in child process: %d (pid=%d)\n", fd,(int) getpid());
    }
    else 
    {
        write(fd,"parent writes a line.\n",strlen("parent writes a line."));
        printf("file descriptor in parent process: %d (pid=%d)\n", fd,(int) getpid());
    }
    FILE *fp;
    fp = fopen("./2.text","r");
    int ch;
    printf("file contents: (pid:%d)\n",(int) getpid());
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp);
    close(fd);
    return 0;
}