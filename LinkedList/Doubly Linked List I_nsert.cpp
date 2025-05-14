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
void insert_Linked_List(struct Node **head,int value)
{
struct Node *newNode,*temp;
temp=*head;
newNode=(struct Node *)malloc(sizeof(struct Node));
newNode->data=value;
newNode->pre=NULL;
    newNode->next=*head;
    if(temp !=NULL)
    {
      temp->pre=newNode;
    }
    *head=newNode;

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
    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct Node *head=created_Linked_list(arr,size);
    cout<<"BEfore inserting"<<endl;
     print(head);
    insert_Linked_List(&head,5);
     cout<<endl<<"After inserting"<<endl;
    print(head);
}
