#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct buffer
{
 long msgid;
 char msg[100];
}message;
int main()
{
 key_t key;
 key=25122;
 int quid=msgget(key,0666|IPC_CREAT);
 msgrcv(quid,&message,sizeof(message),1,0);
 printf("Meaasge received is : %s \n",message.msg);
 msgctl(quid,IPC_RMID,NULL);
 return 0;
}