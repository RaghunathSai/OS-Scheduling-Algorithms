#include<stdio.h>   //Shortest Job First
#include<stdlib.h>
struct scheduling
{
 int arrtime;
 int sertime;
 int waittime;
 int turntime;
 int comptime;
 int starttime;
 int serviced;
}process[10];

int n=0,currtime=0;
int sjf();
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
  process[i].serviced=0;
 }
 
 int count=0;
 while(count<=n)
 {
   temp=sjf();
  if(temp==-1)
   currtime++;
  else
   {
    process[temp].starttime=currtime;
    process[temp].comptime=currtime+process[temp].sertime;
    process[temp].turntime=process[temp].comptime-process[temp].arrtime;
    process[temp].waittime=process[temp].starttime-process[temp].arrtime;
    currtime=currtime+process[temp].sertime;
    awaittime=awaittime+process[temp].waittime;
    aturntime=aturntime+process[temp].turntime;
    count++;
   }
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

int sjf()
{
  int ser[10];
  int i=0,temp=9999,index=-1;
  while(i<n)
  {
    if(process[i].serviced==0 && currtime>=process[i].arrtime)
    {
     if(temp>=process[i].sertime)
     {  
       temp=process[i].sertime;
       index=i;
     }
    }
    i++;
  }
  if(index==-1)
  {
   return -1;
  }
  else
  {
    process[index].serviced=1;
    return index;
  }
}