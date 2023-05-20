#include <stdio.h> 
#include <math.h>
#include <sys/sem.h>//for the semaphore
#include <stdlib.h>
#include <time.h>

#include <string.h>
#define SIZE 200


sem_t *semophore;// synch semaphore

struct cars_queue
{
    int front;
    int rear;
    int size;
    int cars[SIZE];
}cars_fifo = {-1,-1,-1,-1,-1};

struct sharedmemory
{   
    float run_time;
    float t[SIZE];//waiting time in the queue     
    float arrive[SIZE];//arriving time to the queue     
    struct cars_queue cars_fifo; /// the stations on fiio
    int washingMachine[5]; /// 5 washing machines
    int stat; /// start
    int finished;//number of cars that finished washings
    int stoped;//ctrl c 
}sharedmemory;

int get_station(struct sharedmemory* sM, int num)
{
    int i=0;
    while (i<num)
    {
        if(sM->washingMachine[i]!=0)
		{
            i++;
		}
        else
		{
            return i;
		}			
    }  
}

void Dqueue(struct sharedmemory* sM){
    if (sM->cars_fifo.size<0)
	{
        printf("queue is empty");
	}

    else        
    {
        sM->cars_fifo.size--;
        sM->cars_fifo.front++;
    }   
}

void enqueue(struct sharedmemory* sM,int pid){
    if (sM->cars_fifo.size<SIZE)
    {
        if (sM->cars_fifo.size >= 0)
        {
        sM->cars_fifo.cars[sM->cars_fifo.rear+1] = pid;
            sM->cars_fifo.rear++;
            sM->cars_fifo.size++; 
         
        }    
        else
        {
            sM->cars_fifo.cars[0] = pid;
            sM->cars_fifo.front=sM->cars_fifo.rear=0;
            sM->cars_fifo.size = 1;
        } 
    }
    else
	{
        printf("queue is full");
	}
}

void wash(struct sharedmemory* sM,float t1, int s, int p, int n)
{
    sem_t *sem3;// synch semaphore
    sem3 = sem_open("Semaphore3",O_CREAT|O_EXCL,2018,1);//initializing the semaphore
    sem_unlink("Semaphore3");

    fflush(stdout);      
    sem_wait(sem3);
    float time_ = sM->run_time-sM->arrive[p];
    sM->t[p] = time_;//add waiting time
    sem_post(sem3);
   
    sleep(time_);//sleep for the waiting time
        
    sem_wait(semophore);
    int place = sM->cars_fifo.front;
    Dqueue(sM);
    printf("ID of car: %d\n started time=  %f\ninsert into wasching machine: %d\n\n", n, sM->arrive[p]+time_ , s+1);
    sem_post(semophore);

    sleep(t1);//sleep for the washing time sleep
    
    sem_wait(semophore);
    printf("TID of car: %d\nThe car came out from machine\nend time: %f\n\n", n, sM->arrive[p]+ time_+t1);
    fflush(stdout);
    sM->washingMachine[s] = 0;
    usleep(6);
    sem_post(semophore);    
    sM->finished++;

}

float nextTime(float rate){
    return -logf(1.0f - (float)rand() / (RAND_MAX+1.0)) / rate;
}


