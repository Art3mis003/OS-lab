#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>



void *sum(int *args)
{
    int *res=(int *)calloc(1,sizeof(int));
    *res=0;
    int n = *((int *)args);
    for(int i=1;i<=n;i++)
    {
        *res+=args[i];
    }
    pthread_exit((void *)res);
}

int main()
{
    int n;
    printf("enter  the number of elements in the array\n");
    scanf("%d",&n);
    int *arr=(int *)calloc(n+1,sizeof(int));
    arr[0]=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int *result;
    pthread_t thread;
    pthread_create(&thread,0,&sum,(void *)arr);
    pthread_join(thread,(void **)&result);
    printf("sum=%d\n",*result);
    return 0;
}