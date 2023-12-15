#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void *even(void *param)
{
    int *arr=(int *)param;
    int lower=arr[0];
    int higher=arr[1];
    int *sieve=(int *)calloc(higher,sizeof(int));
    for(int i=0;i<higher;i++)
    {
        sieve[i]=1;
    }
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i<=higher;i++)
    {
        if(sieve[i]==1)
        {
            for(int j=i*i;j<=higher;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    pthread_exit((void *)sieve);

}

int main()
{
    pthread_t thread;
    int lower;
	printf("enter lower limit:\n");
	scanf("%d",&lower);
    int higher=21;
    int *arr=(int *)calloc(17,sizeof(int)),*res;
    arr[0]=lower;
    arr[1]=higher;
    pthread_create(&thread,0,&even,(void *)arr);
    pthread_join(thread,(void **)&res);
    for(int i=lower;i<=higher;i++)
    {
        if(res[i]==1)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;

}