#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
 int p1[2],p2[2];
 char ip[]="Hello Parent";
 char op[]="Hello Child";
 pid_t p;
 if(pipe(p1)==-1)
 {
  printf("Pipe1 creation failed");
  return 0;
 }
 if(pipe(p2)==-1)
 {
  printf("Pipe2 creation failed");
  return 0;
 }
 p=fork();
 if(p<0)
 {
  printf("Child creation failed");
  return 0;
 }
 else if(p>0)
 {
  char temp[100];
  write(p1[1],op,100);
  close(p1[1]);
  wait(NULL);
  read(p2[0],temp,100);
  printf("Message from child to parent is %s \n",temp);
  close(p2[0]);
 }
 else
 {
  char temp2[100];
  read(p1[0],temp2,100);
  printf("Message from parent to child is : %s \n",temp2);
  close(p1[0]);
  write(p2[1],op,100);
  close(p2[1]);
  exit(0);
 }
 return 0;
}