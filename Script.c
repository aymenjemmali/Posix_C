
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t  AB , BC , CD , FB,EC;



void* foncMR1(void* arg){

printf("MR1 At Station A  \n ");
printf("MR1 Leaving  Station A to B  \n ");
pthread_mutex_lock(&AB);
usleep(6000);
pthread_mutex_unlock(&AB);
printf("MR1 Arrived at Station B  \n ");

printf("MR1 Leaving  Station B to C  \n ");
pthread_mutex_lock(&BC);
usleep(6000);
pthread_mutex_unlock(&BC);
printf("MR1 Arrived at Station C  \n ");

printf("MR1 Leaving  Station C to D  \n ");
pthread_mutex_lock(&CD);
usleep(6000);
pthread_mutex_unlock(&CD);
printf(" MR1 Arrived at Station D  \n ");

}


void* foncMR2(void* arg){

printf("MR2 : At Station F \n");

printf("  MR2 Leaving  Station F to B  \n");
pthread_mutex_lock(&FB);
usleep(6000);
pthread_mutex_unlock(&FB);
printf("    MR2 Arrived at Station B  \n");

printf(" MR2 Leaving  Station B to A \n");
pthread_mutex_lock(&AB);
usleep(6000);
pthread_mutex_unlock(&AB);
printf(" MR2 Arrived at Station A  \n");


}

void* foncMR3(void* arg){

printf("MR3 : At Station F");
printf("MR3 Leaving  StaEion F to C  \n");
pthread_mutex_lock(&EC);
usleep(6000);
pthread_mutex_unlock(&EC);
printf("MR3 Arrived at Station C  \n");

printf("MR3 Leaving  Station C to B  \n");
pthread_mutex_lock(&BC);
usleep(6000);
pthread_mutex_unlock(&BC);
printf("MR3  Arrived at Station B  \n");


}


int main(int argc, char *argv[])
{
pthread_t  MR1, MR2, MR3;
pthread_mutex_init(&AB, NULL);
pthread_mutex_init(&BC, NULL);
pthread_mutex_init(&CD, NULL);

pthread_create(&MR1, NULL, foncMR1, NULL);
pthread_create(&MR2, NULL, foncMR2, NULL);
pthread_create(&MR3, NULL, foncMR3, NULL);
pthread_join(MR1, NULL);

pthread_join(MR2, NULL);

pthread_join(MR3, NULL);


}

