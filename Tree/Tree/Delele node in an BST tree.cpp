#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *createBST(node *root, int value)
{
    if(root == NULL)
    {
        node *ptr = new(node);
        ptr->data=value;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }
    if(root->data <value)
     {
        root->right=createBST(root->right,value);
     }
    else if(root->data >value)
      {
        root->left=createBST(root->left,value);
      }
      return root;
}
void inorder(node *root)
{
    if(root ==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* findMin(node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
node *DeleteNode(node *root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data<value)
    {
        root->right=DeleteNode(root->right,value);
    }
    else if(root->data>value)
    {
        root->left=DeleteNode(root->left,value);
    }
    else
    {
        if(root->right==NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root ->left==NULL)
        {
            node *temp =root->right;
            delete root;
            return temp;
        }
        else if(root ->right==NULL)
        {
            node *temp =root->left;
            delete root;
            return temp;
        }
        else {
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    node *root=NULL;

        root=createBST(root,5);
        root=createBST(root,4);
        root=createBST(root,2);
        root=createBST(root,9);
        root=createBST(root,10);
        root=createBST(root,16);
        root=createBST(root,11);
        for(int i=0;i<7;i++)
        {
            cout<<root->data<<" " ;

        }
    ////inorder(root);
    cout<<endl;
    DeleteNode(root,9);
    //inorder(root);
}
