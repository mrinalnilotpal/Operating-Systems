#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

sem_t wrt;
pthread_mutex_t mutex;
int numreader = 0;

void *writer(void *wno)
{
    sem_wait(&wrt);
    printf("Writer %d writes\n",(*((int *)wno)));
    sem_post(&wrt);

}
void *reader(void *rno)
{      pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader == 1) {
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    printf("Reader %d: reads\n",*((int *)rno));

    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader == 0) {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{

    pthread_t read[10],write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);
    int i;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    for(i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for(i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    for(i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;

}
