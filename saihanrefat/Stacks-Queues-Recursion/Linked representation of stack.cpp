#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *TOP=NULL;
    void push(int value)
    {
        struct Node *nn;
        nn=(struct Node *)malloc(sizeof(struct Node));
        if(nn==NULL)
        {
            cout<<"Doesnot empty"<<endl;
            return;
        }
        nn->data=value;
        nn->next=TOP;
        TOP=nn;
    }
void pop()
{
    struct Node *temp=TOP;
    if(TOP==NULL)
    {
        cout<<"Empty Linked List"<<endl;
        return;
    }
    int poped=temp->data;
    TOP=TOP->next;
    free(temp);

}
void print()
{
    struct Node *tem;
    tem=TOP;
    if(TOP==NULL)
    {
        cout<<"Empty linked List"<<endl;
        return ;
    }
    while(tem!=NULL)
    {
        cout<<tem->data<<"->";
        tem=tem->next;
    }
    cout<<"NULL";
}
int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    push(30);
    cout<<"Before pop"<<endl;
    print();
     cout<<endl<<"After pop"<<endl;
     pop();
    print();
}
