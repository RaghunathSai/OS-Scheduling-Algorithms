#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
 int shmid;
 key_t key;
 key=5122;
 char *msg;
 shmid=shmget(key,1024,0666|IPC_CREAT);
 printf("Shm id is %d \n",shmid);
 msg=(char *) shmat(shmid,(void*)0,0);
 printf("Message  in the shared memory is %s \n",msg);
 return 0;
}