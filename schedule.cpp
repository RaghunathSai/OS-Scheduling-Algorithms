/*
* Note: First, enter a number for number of processes 
* then press the space or enter button 
* then enter start time then burst time (with the distance between them), 
* then again enter start time and burst time, 
* then the flow continues as much as the number of processes
* finally, press the submit.
* sample input:
                3 2 3 4 5 6 1
3: processes number.
2, 4 and 6: start times.
3 , 5 and 1: burst times.
 
* created on jan.23.2018 by coder.
*
*///This my gift for students :)

#include <iostream>
using namespace std;

class pclass 
{
 public: pclass(); 
  void input1();
  void output(); 
  void FCFS(); 
  void SPN(); 
  void HRRN(); 
  double avgs[3][2]; 
 private:
         double st1[10], bt1[10]; 
         static int n=0; 
};

int main()
 {
  pclass x; 
  x.input1();
  x.output(); 
  cout<<"avrage waiting time:\n\n"; 
  cout<<"FCFS: " ; 
  x.FCFS(); 
  cout<<x.avgs[1][0]; 
  cout<<"\n\nSPN: "; 
  x.SPN(); 
  cout<<x.avgs[2][0]; 
  cout <<"\n\nHRRN: "; 
  x.HRRN();
  cout<<x.avgs[0][0];
  
  cout<<"\n\n\n///////////////////////////////////////\n\n\n"; 
  
  cout<<"avrage total time:\n\n"; 
  cout<<"FCFS: "<<x.avgs[1][1]; 
  cout<<"\n\nSPN: "<<x.avgs[2][1]; 
  cout <<"\n\nHRRN: "<<x.avgs[0][1]; 
  cout<<endl; 
  return 0;
 }
 

pclass::pclass()
{

}

void pclass::input1()
{
   cin>>n; // Enter the number of processes.
   
   for (int i=0 ; i<n ; i++)
   {    
       cin>>st1[i];//for enter Start Time.
       cin>>bt1[i];//for enter Burst Time.
   }
 }   

/////////////////////////////////////////////////
void pclass::output()
{
 cout<<"The processes number: "<<n<<endl;
 cout<<"\nTimes: \n";
 for (int i=0 ; i<n ; i++)
   {
       cout<<"q"<<i+1<<">>"<<endl;
       cout<<"Start Time: " <<st1[i]<<endl;
       cout<<"Burst Time: "<<bt1[i]<<endl<<endl;
       
   }
      cout<<"***************************************\n\n\n";

}

/////////////////////////////////////////////////////
void pclass::HRRN()
{
    double st[10], bt[10]; 
    // st: start time. bt: burst time.
    double  wt=0, tt=0, r, r1, l,l1;
    // wt: waiting time, tt: total time.
    double sum=0, sumwt=0 , avgwt=0, avgtt=0 ;
    // avgwt: avrage waiting time, avgtt: avrage total time.

    for (int i=0; i<n; i++)
     {
        st[i]=st1[i];
        bt[i]=bt1[i];
     }
    for (int i=0; i<n; i++)
    {
        if(i==0) sum=0;
        else if(sum<=st[i-1]) sum=st[i-1]+bt[i-1];
        else sum+=bt[i-1];
        
        for (int j=i+1; j<n; j++)
        {
            r=sum-st[i];
            r1=sum-st[j];
            l=(sum-st[i])/bt[i];
            l1=(sum-st[j])/bt[j];
            if((r<0 && r1<0) && r1>r)
            {
               swap(st[i], st[j]);
               swap(bt[i], bt[j]);
               continue;
            }
            else if ((r<0 ^ r1<0) && r1>=0)
            {
               swap(st[i], st[j]);
               swap(bt[i], bt[j]);
               continue;
            }
            else if((r>=0 && r1>=0) && l1>l)
            {
               swap(st[i], st[j]);
               swap(bt[i], bt[j]);
            }
        }
    }
    sum=0;
    for (int i=0; i<n; i++)
    {
        if(sum<=st[i])
        {
         wt=0;
         sum=st[i];
         }
        else wt=sum-st[i];
        sumwt+=wt;
        tt+=wt+bt[i];
        sum+=bt[i];
    }
    avgwt=sumwt/(n);
    avgtt=tt/(n);
    
    avgs[0][0]=avgwt;
    avgs[0][1]=avgtt;

}



///////////////////////////////////////////////////////
void pclass::FCFS()
{
    double st[100], bt[100];
    double  wt=0, tt=0;
    double sum=0, sumwt=0, avgwt=0, avgtt=0;

    for (int i=0; i<n; i++)
     {
        st[i]=st1[i];
        bt[i]=bt1[i];
     }

    for (int i=0 ; i<n; i++)
        for (int j=i+1; j<n; j++)  //***
            if (st[j]<st[i])
            {
                swap (st[j], st[i]);
                swap (bt[j], bt[i]);
            }
    for (int i=0; i<n; i++)
    {
        if(sum<=st[i])
        {
         wt=0;
         sum=st[i];
         }
        else wt=sum-st[i];
        sumwt+=wt;
        tt+=wt+bt[i];
        sum+=bt[i];
     }
     avgwt=sumwt/(n);
     avgtt=tt/(n);
        
     avgs[1][0]=avgwt;
     avgs[1][1]=avgtt;
}

///////////////////////////////////////////////////////////
void pclass::SPN()
{
    double st[10], bt[10];
    double  wt=0, tt=0, r, r1;
    double sum=0, sumwt=0 , avgwt=0, avgtt=0 ;

    for (int i=0; i<n; i++)
     {
        st[i]=st1[i];
        bt[i]=bt1[i];
     }
    for (int i=0; i<n; i++)
    {
        if(i==0) sum=0;
        else if(sum<=st[i-1]) sum=st[i-1]+bt[i-1];
        else sum+=bt[i-1];
        for (int j=i+1; j<n; j++)
        {
            r=sum-st[i];
            r1=sum-st[j];
            if((r<0 && r1<0) && r1>r)
            {
               swap(st[i], st[j]);
               swap(bt[i], bt[j]);
               continue;
            }
            else if ((r<0 ^ r1<0) && r1>=0)
            {
               swap(st[i], st[j]);
               swap(bt[i], bt[j]);
               continue;
            }
            else if((r>=0 && r1>=0) && bt[j]<bt[i])
            {
               swap(st[i], st[j]);
               swap(bt[i], bt[j]);
            }
        }
    }
    sum=0;
    for (int i=0; i<n; i++)
    {
        if(sum<=st[i])
        {
         wt=0;
         sum=st[i];
         }
        else wt=sum-st[i];
        sumwt+=wt;
        tt+=wt+bt[i];
        sum+=bt[i];
    }
    avgwt=sumwt/(n);
    avgtt=tt/(n);
        
    avgs[2][0]=avgwt;
    avgs[2][1]=avgtt;

}
////////////////////////////////////////////////////////////
