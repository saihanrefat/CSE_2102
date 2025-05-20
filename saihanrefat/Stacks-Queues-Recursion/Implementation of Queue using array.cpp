#include<iostream>
#define max 10
using namespace std;
int queue[max];
int front=-1;
int rear =-1;
void enqueue(int val)
{
    if(rear>max-1)
    {
        cout<<"OVERFLOW"<<endl;
        return;
    }
    if(front<0)
    {
        front++;
    }
    rear=rear+1;
    queue[rear]=val;
}
int dequeue()
{
    if(rear<0)
    {
        cout<<"UNDERFLOW"<<endl;
        return 0;
    }
    return queue[front++];

}
int peek()
{
     if(rear<0)
    {
        cout<<"UNDERFLOW"<<endl;
        return 0;
    }
    return queue[front];
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    for(int i=front;i<rear+1;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
    dequeue();
    dequeue();
    for(int i=front;i<rear+1;i++)
    {
        cout<<queue[i]<<" ";
    }
}
