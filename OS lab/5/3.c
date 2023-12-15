#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void *even(void *param){
    int *arr=(int *)param;
    int lower=arr[0];
    int higher=arr[1];
    for(int i=lower;i<=higher;i++){
        if(i%2==0){
            printf("%d ",i);
        }
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t thread;
    int lower;
    printf("enter lower limit:\n");
    scanf("%d",&lower);
    int higher;
    printf("enter higher limit:\n");
    scanf("%d",&higher);
    int *arr=(int*)calloc(2,sizeof(int));
    arr[0]=lower;
    arr[1]=higher;
    pthread_create(&thread,0,&even,(void *)arr);
    pthread_join(thread,NULL);
    printf("\n");
    return 0;
    
}