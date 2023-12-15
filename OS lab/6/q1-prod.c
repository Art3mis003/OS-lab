#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <string.h>

#define name "fifo"
#define buffer 1000
int main(int argc, char const *argv[]){
int pipe_fd;
 int res;
 int open_mode=O_WRONLY;
 int n=0;
 char buf[buffer+1];
 
 if(access(name,F_OK)==-1)
 {
 res=mkfifo(name,0777);
 
 }
 
 printf("Process %d opening FIFO O_WRONLY\n",getpid());
 pipe_fd=open(name,open_mode);
 printf("Process %d result %d\n",getpid(),pipe_fd);
 
 if (pipe_fd!=-1)
 {
 printf("Enter 4 numbers\n");
 
	while(n<4)
	{
	scanf("%s",buf);
	res=write(pipe_fd,buf,buffer);
	n++;
	}
 (void)close(pipe_fd);
 }
 else
 exit(EXIT_FAILURE);
 
 printf("Process %d Finished\n",getpid() );
 exit(EXIT_SUCCESS);
}