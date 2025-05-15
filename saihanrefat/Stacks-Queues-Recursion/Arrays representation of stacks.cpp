#include<iostream>
#include<stdlib.h>
#define CAPACITY 10
using namespace std;
int stack[CAPACITY];
int TOP=-1;
void push(int val)
{
    if(TOP>=CAPACITY-1)
    {
        cout<<"OVERFLOW"<<endl;
        return;
    }
    else
    {
        TOP=TOP+1;
        stack[TOP]=val;
    }
}
int pop()
{
    if(TOP<0)
    {
        cout<<"UNDERFLOW"<<endl;
        return 0;
    }
    else
    {
       int val=stack[TOP];
       TOP=TOP-1;
       return val;
    }
}
int peek()///value return but not remove
{
    if(TOP>=0)
    {
        return stack[TOP];
    }
    else
    {
        return -1;
    }
}
void print()
{
    for(int i=0;i<=TOP;i++)
    {
        cout<<stack[i]<<" ";
    }
}
int main()
{
    pop();
    print();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    print();
    cout<<endl<<" Before pop=";
    push(10);
    print();
    cout<<endl<<"After pop = ";
    pop();
    print();
     cout<<endl<<"After peek = ";
    peek();
    print();
}
