#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
    printf("[*] parent process starting\n");
    int r_val= fork();
    switch (r_val)
    
    {
    case -1:
        perror("error in fork\n");
        exit(EXIT_FAILURE);
        break;
    case 0:
        printf("[**]child process starting\n");
        pid_t pid= getpid();
        printf("child pid=%d\n",pid);
        for(int i=0; i<10;i++){
            sleep(1);
            printf("Sleeping for %d seconds\n",i);
        }
    default:
        pid_t ppid=getpid();
        printf("parent pid=%d\n",ppid);
        wait(NULL);
        printf("child process terminated\n");
        exit(0);
        break;
    }

}