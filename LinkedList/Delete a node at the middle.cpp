#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *CreatedLinkedList(int arr[],int size)///Created a Link List
{
    struct Node *head=NULL,*current=NULL,*temp=NULL;
    for(int i=0;i<size ;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
            if(head== NULL)
            {
                head=temp;
                current=temp;
            }
            else
            {
                current->next=temp;
                current=current->next;
            }
    }
    return head;
}
void DeleteNode(struct Node *head,int value)///Delete a node
{
 struct Node *temp,*pre=NULL;
 temp=head;
 if(head==NULL)
 {
     cout<<"Linked List is Empty"<<endl;
     return ;
 }
 else if(head->data==value)
 {
     cout<<"NULL"<<endl;
     return ;
 }
 while(temp->next !=NULL && temp->data !=value)
 {
     pre=temp;
     temp=temp->next;
 }
 if(temp->data==value)
 {
     pre->next=temp->next;

 }
 else
 {
     cout<<"Value are not exists in the Linked List"<<endl;
     return;
 }
}
void printLinkListed(struct Node *head)///Print a Linked List
{
    while(head !=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}
int main()///Main function
{
    int arr[]={3,6,8,9,0,54,2,1,34,56,7};
    int length=sizeof(arr)/sizeof(arr[0]);
   struct Node *temp;
   temp= CreatedLinkedList(arr,length);
   DeleteNode(temp,34);
   printLinkListed( temp);
}
