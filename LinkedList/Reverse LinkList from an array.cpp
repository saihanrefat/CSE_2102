
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
int data;
struct Node *next;
};
struct Node *LinkedList(int arr[],int size)
{
    struct Node *head=NULL,*current=NULL,*temp=NULL;
    for(int i=0;i<size;i++)
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

};
struct Node *ReverseLinkedList(struct Node *head)
{
    struct Node *pre=NULL,*current=head,*next=NULL;
    while(current !=NULL)
    {
        next=current->next;
        current->next=pre;
        pre=current;
        current=next;

    }
    return pre;
};
int main()
{
     int n;
    printf("Array size:");
    scanf("%d",&n);
    int arr[n];
    printf("Array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Node *head=NULL;
    head=LinkedList(arr,n);
    head=ReverseLinkedList(head);
    while(head !=NULL)
     {
      cout<<head->data<<"->";
      head=head->next;
     }
     cout<<"NULL\n";
    return 0;

}

