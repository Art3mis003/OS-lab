#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<errno.h>

#define Max 512
int main(int argc,char const *argv[]){
    struct msg_st{
        long int type;
        int msg;
    };
    int running=1;
    struct msg_st data;
    int num;
    int msgid;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid==-1){
        exit(EXIT_FAILURE);
    }
    while(running){
        printf("enter a number:\n");
        scanf("%d",&num);
        data.type=1;
        data.msg=num;
        if(msgsnd(msgid,(void*)&data,Max,0)==-1){
            exit(EXIT_FAILURE);
        }
        if(num==-1){
            running=0;
        }
        exit(EXIT_SUCCESS);

    }

}