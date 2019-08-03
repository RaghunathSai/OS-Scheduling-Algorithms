#include<stdio.h>
#include<stdlib.h>
struct scheduling
{
 int arrtime;
 int sertime;
 int waittime;
 int turntime;
 int comptime;
 int starttime;
}process[10];

int main()
{
 int n,currtime=0,i;
 float awaittime=0.0,aturntime=0.0;
 printf("Enter the no.of process :");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
 {
  printf("Enter the arrival time and burst time of process number %d  : ",(i+1));
  scanf("%d %d",&process[i].arrtime,&process[i].sertime);
 }
 i=0;
 do
 {
  if(currtime>=process[i].arrtime)
  {
   process[i].starttime=currtime;
   process[i].comptime=currtime+process[i].sertime;
   process[i].turntime=process[i].comptime-process[i].arrtime;
   process[i].waittime=process[i].starttime-process[i].arrtime;
   currtime=currtime+process[i].sertime;
   awaittime=awaittime+process[i].waittime;
   aturntime=aturntime+process[i].turntime;
   i++;
  }
  else
   currtime++;
 }while(i<n);
 awaittime=(awaittime/n);
 aturntime=(aturntime/n);
 printf("Process No.   Arrtime.  Sertime.  Turntime.  Waittime. \n ");
 for(i=0;i<n;i++)
 {
  printf(" %d \t\t  %d \t  %d \t   %d  \t \t%d \n",i+1,process[i].arrtime,process[i].sertime,process[i].turntime,process[i].waittime);
 }
 printf("Average Wating time is : %f \n",awaittime);
 printf("Average Turn Around Time is : %f \n",aturntime);
 return 0;
}