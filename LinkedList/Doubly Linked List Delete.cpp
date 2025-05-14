#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
};
struct Node *created_Linked_list(int arr[],int size)
{
    struct Node *head=NULL,*current=NULL,*temp=NULL;
        for(int i=0;i<size;i++)
        {
            temp=(struct Node*)malloc(sizeof(struct Node));
            temp->data=arr[i];
            temp->pre=NULL;
            temp->next=NULL;
            if(head== NULL)
            {
                head=temp;
                current=temp;
            }
            else
            {
                current->next=temp;
                temp->pre=current;
                current=current->next;
            }
        }
        return head;
};
void delete_Linked_List(struct Node **head,int value)
{
struct Node *newNode,*temp;
temp=*head;
while(temp!=NULL && temp->data !=value)
{
    temp=temp->next;
}
if(temp==NULL)
{
    cout<<"Value does not exists"<<endl;
    return;
}
if(temp==*head)
{
    *head=temp->next;
    if(*head != NULL)
    {
        (*head)->pre=NULL;
    }
}
if(temp->pre !=NULL)
{
    temp->pre->next=temp->next;
}
if(temp->next !=NULL)
{
    temp->next->pre=temp->pre;
}
}
void print(struct Node *head)
{
    struct Node *temp=head;
    while(temp != NULL)
    {
        cout<< temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int arr[]={1,2,4,8,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct Node *head=created_Linked_list(arr,size);
    cout<<"Before deleting"<<endl;
    print(head);
   delete_Linked_List(&head,4);
    cout<<"After deleting"<<endl;
    print(head);
}
