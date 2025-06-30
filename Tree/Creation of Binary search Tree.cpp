#include<iostream>
using namespace std;
struct node
{
    int data;
    node *Lroot;
    node *Rroot;
};
node *creationBst(node *root,int item)
{
    if(root==NULL)
    {
        node *ptr=new(node);
        ptr->data=item;
        ptr->Lroot=NULL;
        ptr->Rroot=NULL;
        return ptr;
    }
    else if(item<root->data)
    {
        root->Lroot=creationBst(root->Lroot,item);
    }
    else
    {
        root->Rroot=creationBst(root->Rroot,item);
    }
    return root;
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
        root=creationBst(root,item);
    }

}
