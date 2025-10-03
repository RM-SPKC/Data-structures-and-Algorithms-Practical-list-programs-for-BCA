#include<iostream>
using namespace std;
#define N 5
class  priority
{
public:
    int dq[N];
    int pq[N];
    int count;
    priority()
    {
     count=0;
    }
    void enqueue();
    void dequeue();
    void peek();
    void display();
};
void priority::enqueue()
{
  int d,p;

  if(count==N)
  {
      cout<<"\n\tQueue is full";
  }
  else
  {
      cout<<"Enter the data : ";
      cin>>d;
      cout<<"Enter  the priority : ";
      cin>>p;
      dq[count]=d;
      pq[count]=p;
      count++;
  }
}
void priority::dequeue()
{
int high;
if(count==0)
  {
      cout<<"\n\tEmpty Queue";
  }
  else
  {
      high=0;
      for(int i=1;i<count;i++)
      {
          if(pq[i]<pq[high])
            high=i;
      }
      cout<<"\n\tDeleted Element : "<<dq[high]<<"(Priority="<<pq[high]<<")";
      for(int i=high;i<=count-1;i++)
      {
          dq[i]=dq[i+1];
          pq[i]=pq[i+1];
      }
      count--;
  }
}
void priority::peek()
{
int high;
if(count==0)
  {
      cout<<"\n\tEmpty Queue";
  }
  else
  {
      high=0;
      for(int i=1;i<count;i++)
      {
          if(pq[i]<pq[high])
            high=i;
      }
      cout<<"\n\tFront Element : "<<dq[high]<<"(Priority="<<pq[high]<<")" ;
  }
}
void priority::display()
{
  if(count==0)
  {
      cout<<"\n\tEmpty Queue\t";
  }
  else
  {
   cout<<"\n\tFront\t";
   for(int i=0;i<count;i++)
   {
       cout<<" <-- "<<dq[i]<<"(Priority="<<pq[i]<<")";
   }
   cout<<" <-- Rear\n";
  }
}
int main()
{
   priority pq;
   int c;
   cout<<"\n\t\t\tPriority Queue";
   cout<<"\n\t\t\t---------------";
   cout<<"\n1.Enqueue";
   cout<<"\n2.Dequeue";
   cout<<"\n3.Peek";
   cout<<"\n4.Display";
   cout<<"\n5.Exit";
   do
   {
     cout<<"\nEnter your choice:";
     cin>>c;
     switch(c)
     {
       case 1:
          pq.enqueue();
          break;
       case 2:
          pq.dequeue();
          break;
       case 3:
          pq.peek();
          break;
       case 4:
          pq.display();
          break;
       case 5:
          cout<<"\n\tExiting.....";
          break;
       default:
          cout<<"\n\tEnter the choice between 1-5:";
     }
   }while(c!=5);
   return 0;
}
