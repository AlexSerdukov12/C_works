#include <string.h>
#include <unistd.h>
#include <stdio.h> 
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>

#include <signal.h>
#include "shm.c"
#include <time.h>
#include <errno.h>


#define SIZE 200
struct sharedmemory* sM;
void ctrl_c(); ///cntrl+c signal for child to talk


int main(int argc, char const *argv[])
{
    srand(time(0)); 
    key_t k;
    int shmd;
    int r_pid;
    

    k = ftok(".", 'T');
    if((shmd = shmget(k, 30*sizeof(sM), IPC_CREAT|IPC_EXCL|2018))== -1)
    {
        if((shmd = shmget(k, SIZE, 0))== -1)
        {
            perror("bad segment");
            exit(1);
        }
    }


    
    if ((sM = (struct sharedmemory*) shmat(shmd, NULL, 0)) == NULL)
    {
        perror("shmat");
        exit(1);
    }
    
   
    ////////////////// all samophores
    semophore = sem_open("Semaphore",O_CREAT|O_EXCL,2018,1);
    sem_unlink("Semaphore");

    sem_t *sem1;// synch semaphore
    sem1 = sem_open("Semaphore1",O_CREAT|O_EXCL,2018,atoi(argv[1]));
    sem_unlink("Semaphore1");

    sem_t *sem2;// synch semaphore
    sem2 = sem_open("Semaphore2",O_CREAT|O_EXCL,2018,1);
    sem_unlink("Semaphore2");



    signal(SIGINT, ctrl_c);//signal for ctrl_c 
    sM->run_time = 0.0;//counting the time
    float t_time = nextTime(1/atof(argv[4]));
    printf("%f\n",t_time);
    sM->stat = 1;
    sM->stoped=0;
    sM->finished=0;
    time_t start = time(0);

///////////////// run all time that insert
    while (sM->run_time <= t_time && sM->stat==1)
    {           

        float temp = nextTime(1/atof(argv[2]));////next car in time                                        
        sleep(temp);                                   
        r_pid = fork();
        if (r_pid<0)
		{
            break;
		}
            
        else if (r_pid == 0)
        {           
            signal(SIGINT, ctrl_c);//signal for ctrl_c 
            if (sM->run_time+temp <= t_time&&sM->stat==1)
            {               
                sem_wait(semophore);
                int i = sM->cars_fifo.rear;
                sM->run_time += temp;
                enqueue(sM,getpid());
                sM->arrive[i]=sM->run_time;

                printf("ID of car: %d\n came to queue , time: %f\n\n", getpid(), sM->arrive[i]);

                sem_post(semophore);   
                sem_wait(sem1);// count semaphore   
                sem_wait(sem2);
                if(sM->stoped==1){
                    sem_post(sem1);
                    sem_post(sem2);
                    sM->stat = 0;
                    break;
                }
                int station = get_station(sM, atoi(argv[1]));
                sM->washingMachine[station] = getpid();
                sem_post(sem2);
                wash(sM, nextTime(1/atof(argv[3])), station,i, getpid());
                sem_post(sem1);
                t_time=-5;
                break;                          
            }  
            else
            {
                sM->stat = 0;
                break;   
            }               
        }           
    }    
    
    if(r_pid != 0) ////// father calls
    {                   
        while (r_pid = waitpid(-1, NULL, 0))
        {
            if(errno == ECHILD)
			{
                break;
			}
        }

        printf("\n total of cars : %d.\n", sM->finished );
        fflush(stdout);
        shmctl(shmd, IPC_RMID, 0);
        exit(0);
    } 
}

void ctrl_c()
{
    signal(SIGINT, ctrl_c);
    sM->stoped=1;
}

