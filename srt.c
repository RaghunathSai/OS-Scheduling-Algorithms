#include<stdio.h>   //Shortest Remaning time
#include<stdlib.h>
struct scheduling
{
 int arrtime;
 int sertime;
 int waittime;
 int turntime;
 int comptime;
 int resptime;
 int starttime;
 int remaintime;
}process[10];
// Non preemptive algorithms wait time equal to response time
int n=0,currtime=0;
int srt();
int main()
{
 int i,temp=0;
 float awaittime=0.0,aturntime=0.0;
 printf("Enter the no.of process :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the arrival time and burst time of process number %d  : ",(i+1));
  scanf("%d %d",&process[i].arrtime,&process[i].sertime);
  process[i].remaintime=process[i].sertime;
  process[temp].starttime=999;
 }
 
 int count=0;
 while(count<=n)
 {
   temp=srt();
   if(temp!=-1)
   {
    process[temp].remaintime--;
    int t=process[temp].starttime;
    if(t>currtime)
     process[temp].starttime=currtime;
    if(process[temp].remaintime==0)
    {
     process[temp].comptime=currtime;
     process[temp].turntime=process[temp].comptime-process[temp].arrtime;
     process[temp].resptime=process[temp].starttime-process[temp].arrtime;
     process[temp].waittime=process[temp].comptime-process[temp].arrtime-process[temp].sertime;
     awaittime=awaittime+process[temp].waittime;
     aturntime=aturntime+process[temp].turntime;
     count++;
    }
 }
 currtime++;
   if(count==n)
    break;
  }

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

int srt()
{
  int i=0,temp=9999,index=-1;
  while(i<n)
  {
    if(process[i].remaintime>0 && currtime>=process[i].arrtime)
    {
     if(temp>=process[i].remaintime) 
     {  
       temp=process[i].remaintime;
       index=i;
     }
    }
    i++;
  }
  return index;
}