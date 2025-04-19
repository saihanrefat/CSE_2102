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
int SearchItem(struct Node *head,int value)
{
    int index=1;
  while(head != NULL)
  {
      if(head->data==value)
      {
          return index;
      }
      index++;
      head=head->next;
  }
  return -1;
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
    struct Node *head;
    head=LinkedList(arr,n);
    printf("%d",SearchItem(head,50));

    return 0;

}

