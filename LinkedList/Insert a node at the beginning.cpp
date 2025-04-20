#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *CreatLinkedList(int arr[],int size);
void InsertNode(struct Node *head,int value);
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter array element:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    struct Node *head;
    head = CreatLinkedList(arr,n);
    InsertNode(head,22);
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
void InsertNode(struct Node *head,int value)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=head;
     struct Node *newhead=temp;
    struct Node *current=newhead;
    newhead=temp;
    while(newhead !=NULL)
    {
        cout<<newhead->data<<" ->";
        newhead=newhead->next;
    }
    cout<<"NULL";


}
