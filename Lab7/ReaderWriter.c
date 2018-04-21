#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include<stdlib.h>

int readercount=0;
sem_t mutex;
sem_t Awrite;
int data=0;
void *readerX(void *);
void *writerZ(void *);

void *readerX(void *arg){
    int reader;
    reader=((int)arg);
    sem_wait(&mutex);
    readercount=readercount+1;
    if(readercount==1)
        sem_wait(&Awrite);
    sem_post(&mutex);
    printf("Reader %d is reading the data %d\n",reader,data);
    //sleep(1);
    sem_wait(&mutex);
    readercount=readercount-1;
    if(readercount==0)
       sem_post(&Awrite);
    sem_post(&mutex);
}

void *writerZ(void *arg){
    int reader;
    reader=((int)arg);
    sem_wait(&Awrite);
    data=data+1;
    printf("Writer %d is writing the data %d\n",reader,data);
   //  sleep(1);
    sem_post(&Awrite);
}

int main(int argc, const char * argv[])
{
    int i, NumThreads;
    sem_init(&mutex,0,1);
    sem_init(&Awrite,0,1);

    pthread_t  *readers, *writers;
    NumThreads = abs(atoi(argv[1]));
    readers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);
    writers = (pthread_t *)malloc(sizeof(pthread_t) *NumThreads);

    for (i = 0; i < NumThreads; i++)
    {
  	     pthread_create(&writers[i], NULL, &writerZ,(void *)i);
       	 pthread_create(&readers[i], NULL, &readerX, (void *)i);
    }
    for (i = 0; i < NumThreads; i++)
    {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);

    }

    return 0;
}

