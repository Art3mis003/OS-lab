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

#define max 512
int reverse(int num){
    int rev=0;
    while(num>0){
        rev*=10;
        rev+=num%10;
        num/=10;
    }
    return rev;

}
int main(int argc,char const *argv[]){
    struct msg_st{
        long int type;
        int msg;
    };
    int running=1;
    int msgid;
    long int recv=0;
    struct msg_st data;
    msgid=msgget((key_t)1234,0666|IPC_CREAT);
    
    while(running){
        if(msgrcv(msgid,(void*)&data,BUFSIZ,recv,0)==-1){
            exit(EXIT_FAILURE);
        }
        printf("data received is %d\n",data.msg);
        if(data.msg==-1){
            running=0;
        }

        if(data.msg==reverse(data.msg)){
            printf("palindrome\n");
        }
        else{
            printf("not palindrome\n");
        }
        exit(EXIT_SUCCESS);

    }
}