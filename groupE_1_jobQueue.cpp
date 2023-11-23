/* Group E-1
Queues are frequently used in computer programming, and a typical example is the creation of a
job queue by an operating system. If the operating system does not use priorities, then the jobs
are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue. */


#include<iostream>
using namespace std;
#define SIZE 10

class job_queue
{
    private: int q[SIZE];
             int front,rear;
    public:
             job_queue();
             void enqueue(int id);
             int dequeue();
             bool isEmpty();
             bool isFull();
};

job_queue::job_queue()
{
    front=0;
    rear=-1;
}

bool job_queue::isEmpty()
{
    if(rear==-1)
        return 1;
    else
        return 0;
}

bool job_queue::isFull()
{
    if(rear==SIZE-1)
        return 1;
    else
        return 0;
}

void job_queue::enqueue(int id)
{
    if(!isFull() )
    {
        rear++;
        q[rear]=id;
        cout<<"\n Job is added to Job Queue...";

    }
    else
        cout<<"\n Job Queue is full..Jobs can't be added";
}


int job_queue::dequeue()
{
    int x;
    if(! isEmpty() )
    {
        x=q[front];
        front++;
        return x;
    }
    else
           return -1; //return -1
}


int main()
{
    //add menu driven code
    job_queue Jq;
    int id;

    cout<<"\n Enter Job Id : ";
    cin>>id;
    Jq.enqueue(id);

    cout<<"\n Enter Job Id : "
    cin>>id;
    Jq.enqueue(id);

    id=Jq.dequeue();
    cout<<"\n Deleted "<<id;

    if(id==-1)
        cout<<"\n No job left in queue";


}












