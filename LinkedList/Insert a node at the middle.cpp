#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *CreatLinkedList(int arr[],int size);
struct Node *InsertNode(struct Node *head,int position,int value);
void PrintLinkList(struct Node *head);

int main()
{
    int n,position ,value;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter array element:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter inserting position and value:";
    cin>>position>>value;
    struct Node *head;
    head = CreatLinkedList(arr,n);
   struct Node *temp;
  temp= InsertNode(head,position,value);
    PrintLinkList(temp);
}
void PrintLinkList(struct Node *head)
{
    while(head !=NULL)
    {
      cout<<head->data<<"->";
      head=head->next;
    }
    cout<<"NULL";
}
struct Node *CreatLinkedList(int arr[],int size)
{
    struct Node *head=NULL,*current=NULL,*temp=NULL;
    for(int i=0;i<size;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        if(head==NULL)
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
};
struct Node *InsertNode(struct Node *head,int position,int value)
{
    struct Node *current=head;
   int count=0;
   while(current !=NULL)
   {
       count++;
       if(count==position)
       {
           struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
           temp->data=value;
           temp->next=current->next;
           current->next=temp;
       }
       current=current->next;
   }
   return head;
}

