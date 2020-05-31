// FCFS Number of CPUs are assumed to be 3 but it could be modified
#include <iostream>
using namespace std;

struct Process
{
	int at;
	int threads;
	int ct;
}processes[10];

struct Thread
{
	int pid;
	int at;
	int bt;
	int ft;
	int CPU_id;
}threads[25];

int CPU[]={0,0,0}, n,tc;

void main()
{
	int findFreeCPUCount(int);
	int dispatcher(int);
	int NextAvailableTime();
	void display();
	int completed;
	cout <<"Enter the no of processes:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter arrival time of "<<i<<"th process: ";
		cin>>processes[i].at;
		cout<<"Enter no of theads: ";
		cin>>processes[i].threads;
		for(int j=0;j<processes[i].threads;j++)
		{
			threads[tc].at=processes[i].at;
			threads[tc].pid=i;
			cout<<"Enter the service time of T"<<j<<": ";
			cin>>threads[tc].bt;
			tc++;
		}	
	}
	int ct=0, FreeCPUCount=3;
	while(completed < tc)
	{
		FreeCPUCount= findFreeCPUCount(ct);
		if(FreeCPUCount == 0)  // If no CPU is free then update the current time with next time at which a CPU will become free
		{
			ct= NextAvailableTime();
		}
		while(FreeCPUCount > 0 && completed < tc ) // One or more CPUs are free and not all the threads are completed
		{
			int tid=dispatcher(ct); // Choose the next thread to schedule
			if(tid != -1) //  A thread is ready for execution at the current time
			{
					for(int i=0;i<3;i++) //Identify a CPU that is free right now
					{
						if(CPU[i] <= ct)  // To find whether the ith CPU is currently free
						{
							CPU[i]=ct+threads[tid].bt; // Allocate the ith CPU to thre thread tid
							threads[tid].bt=0; // Thread completed and will not be considered again for scheduling
							threads[tid].ft= CPU[i]; // Finish time is calculated as current time + service time which is already calculated into CPU[i]
							threads[tid].CPU_id = i; // The particular CPU on which the thread is executed is noted
							FreeCPUCount--;     // No of free CPU is decremented by one
							completed++;  // No of completed threads incremented by one
							break;  // Scheduling of the thread is over and so break the for loop 
						}	
					}
			}		
			else  // Increment current time and try to find ready threads
			{
					ct++;
			}
				
		}
		ct++; // Increment current time 
	}
	display();
	
}
int dispatcher(int ct)
{
	for(int i=0;i<tc;i++)
	{
		if(threads[i].at <= ct && threads[i].bt != 0)  // Find the thread that has arrived at the current time & it is not yet completed
		{
			return i;
		}
	}
	return -1;
}
int findFreeCPUCount(int ct)   // To count the number of CPUs that are currently free/available
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		if(CPU[i]<=ct) count++;
	}
	return count;
}
int NextAvailableTime()       // When is the nearest time that a CPU will become available
{
	int tim= 1000;
	for(int i=0;i<3;i++)
	{
		if(CPU[i]<tim)
			tim= CPU[i];
	}
	return tim;
}
void display()
{
	int FindCompletionTime(int);
	cout<<"TID"<<"\t"<<"FT"<<"\t"<<"CPU Id"<<endl;
	for(int i=0;i<tc;i++)
	{
		cout<<i<<"\t"<<threads[i].ft<<"\t"<<threads[i].CPU_id<<endl;
	}
	cout<<"PID"<<"\t"<<"CT"<<endl;
	for(int i=0;i<n;i++)
	{
		int ft = FindCompletionTime(i);
		cout<<i<<"\t"<<ft<<"\t"<<endl;
	}
}
int FindCompletionTime(int pid) // To identify the highest finish time of a thread within process pid
{
		int tid=0,ct=0;
		if(pid!=0)
		{
				for(int j=0;j<pid;j++) // To find out the index of the first thread of process pid
				{
					tid+=processes[j].threads;
				}
		}	
		for(int i=0;i<processes[pid].threads;i++)	// To find the thread of pid with the maximum finish time
		{
			if(threads[tid].ft > ct)
				ct= threads[tid++].ft;
		}
		return ct;
		
}