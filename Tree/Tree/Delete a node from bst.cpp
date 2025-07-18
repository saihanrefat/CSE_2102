
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *lside;
    struct node *rside;
};
struct node *createbst(struct node *root,int value)
{
    if(root==NULL)
    {
        struct node *newnode = new node;
        newnode->data=value;
        newnode->lside=NULL;
        newnode->rside=NULL;
        return newnode;

    }
    if(value>root->data)
    {
      root->rside = createbst(root->rside,value);
    }
    else if(value <root->data)
    {
         root->lside = createbst(root->lside,value);
    }
      return root;
};
struct node *deletenode(struct node *root,int key)
{
    if(root== NULL)
    {
        return root;
    }
    else if(root->data > key)
    {
        root->lside=deletenode(root->lside,key);
    }
    else if(root->data < key)
    {
        root->rside=deletenode(root->rside,key);
    }
    else{
        if(root->lside==NULL && root->rside==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->lside== NULL)
        {
            struct node *temp=root->rside;
            delete root;
            return temp;
        }
        else if(root->rside== NULL)
        {
            struct node *temp=root->lside;
            delete root;
            return temp;
        }
        else
        {
            struct node *succ=root->rside;
            while(succ->lside != NULL)
            {
                succ=succ->lside;
            }
            root->data=succ->data;
            root->rside=deletenode(root->rside,root->data);
        }
    }
    return root;
};
void inorder(struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->lside);
    cout<<root->data<<" ";
     inorder(root->rside);
}
int main ()
{
    struct node *root= NULL;
    int arr[]={77,50,60,22,30,44,55,55};
    for(int i=0;i<8;i++)
    {

        root=createbst(root,arr[i]);
    }
    deletenode(root,60);
    inorder(root);

}
