#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;
struct Node *enqueue(int value)
{
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
        if(front==NULL)
        {
            front=newNode;
            rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=rear->next;
        }
    return front;

}
void print()
{
    struct Node *temp;
    temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
       temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void dequeue()
{
    if(front==NULL)
    {
        cout<<"UNDERFLOW"<<endl;
        return ;
    }
    struct Node *temp=front;
    front=front->next;
    free(temp);
};
int main()
{
     cout<<"BEFORE INSERTING"<<endl;
     print();
    enqueue(5);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    cout<<"BEFORE REMOVING"<<endl;
     print();
    dequeue();
    dequeue();
    dequeue();
    cout<<"AFTER REMOVING"<<endl;
    print();


}
