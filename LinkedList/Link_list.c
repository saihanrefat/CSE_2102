#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *c = NULL;
    a= (struct Node *)malloc(sizeof(struct Node));
    b= (struct Node *)malloc(sizeof(struct Node));
    c= (struct Node *)malloc(sizeof(struct Node));
    a->data=10;
    b->data=30;
    c->data=50;
    a->next=b;
    b->next=c;
    c->next=NULL;
    ///Traverse a Link List
    while(a != NULL)
    {
        printf("%d ->",a->data);
        a=a->next;
    }

}
