#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
int data;
struct Node *next;
};
struct Node *createNode(int value)
{
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertNode(struct Node ** head,int value)
{
    struct Node* newnode=createNode(value);
    if(*head ==NULL)
    {
        *head=newnode;
        return;
    }
    struct Node*temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
};
void print(struct Node *head)
{
    while(head !=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
     cout<<"NULL";
}
struct Node *mergelist(struct Node* L1,struct Node* L2)
{
    if(L1==NULL)
    {
        return L2;
    }
    if(L2==NULL)
    {
        return L1;
    }
    struct Node *result=NULL;
    if(L1->data <L2->data)
    {
       result=L1;
       result->next=mergelist(L1->next,L2);
    }
    else
    {
        result=L2;
       result->next=mergelist(L1,L2->next);
    }
return result;
};
int main()
{
    struct Node*list1=NULL,*list2=NULL;
    struct Node*result;
    insertNode(&list1,1);
    insertNode(&list1,3);
    insertNode(&list1,5);
     print(list1);
     cout<<endl;
    insertNode(&list2,2);
    insertNode(&list2,4);
    insertNode(&list2,6);
    print(list2);
    cout<<endl;
    result=mergelist(list1,list2);
    print(result);
}

