#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_code(void *args)
{
    int n = *((int *)args);
    int *fib = (int *)calloc(n + 1, sizeof(int));
        
    

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    pthread_exit((void *)fib);
}

int main(int argc, char *argv[])
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n + 1, sizeof(int));
    arr[0] = n;
    pthread_t thread;
    pthread_create(&thread, 0,&thread_code, (void *)arr);
    pthread_join(thread, (void **)&arr);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}