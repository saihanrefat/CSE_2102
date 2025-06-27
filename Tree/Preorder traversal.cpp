#include<iostream>
using namespace std;
struct node
{
    int data;
    node *lside;
    node *rside;
};
///Created binary node
node *creationBstNode(node *root,int item)
{
    if(root ==NULL)
    {
        node *ptr=new(node);
        ptr->data=item;
        ptr->lside=NULL;
        ptr->rside=NULL;
        return ptr;
    }
    else if(root->data <item)
    {
        root->rside=creationBstNode(root->rside,item);
    }
    else
    {
        root->lside=creationBstNode(root->lside,item);
    }
    return root;
}
///Preorder traversal
void preorder(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->lside);
        preorder(root->rside);
    }
}
int main()
{
    node *root=NULL;
    int n;
    cout<<"Enter node number: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int item;
        cin>>item;
        root=creationBstNode(root,item);
    }
    preorder(root);
}
