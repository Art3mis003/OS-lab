#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

sem_t barber,customer;
pthread_mutex_t seat;
int free1 =10;
void *br(void *p){
    while(1){
    sem_wait(&customer);
    pthread_mutex_lock(&seat);
    if(free1<10){
        free1++;
        sleep(2);
        printf("customer free: seats left: %d\n",free1);

    }
    sem_post(&barber);
    pthread_mutex_unlock(&seat);
    
}
}

void cr(void *args){
    while(1){
    pthread_mutex_lock(&seat);
    if(free1>0){
        free1--;
        sleep(2);
        printf("customer occupied: seats left: %d\n",free1);
        sem_post(&customer);
        pthread_mutex_unlock(&seat);
        sem_wait(&barber);


    }
    else{
        pthread_mutex_unlock(&seat);
    }


}
}

int main(){
    pthread_t thread[2];
    sem_init(&barber,0,1);
    sem_init(&customer,0,0);
    pthread_mutex_init(&seat,NULL);
    pthread_create(&thread[0],NULL,br,NULL);
    pthread_create(&thread[1],NULL,cr,NULL);
    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
    sem_destroy(&barber);
    sem_destroy(&customer);
    pthread_mutex_destroy(&seat);

}