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
 message.msgid=1;
 printf("Enter the message to send in the queue : \n");
 scanf("%s",message.msg);
 msgsnd(quid,&message,sizeof(message),0);
 printf("Meaasge is sent ");
 msgctl(quid,IPC_RMID,NULL);
 return 0;
}