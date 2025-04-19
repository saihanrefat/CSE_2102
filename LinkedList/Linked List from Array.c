#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
struct Node *LinkedList(int arr[],int size);
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
    struct Node *head;
    head=LinkedList(arr,n);
    while(head !=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
    return 0;

}
struct Node *LinkedList(int arr[],int size)
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
