#include<iostream>
using namespace std;
void DeleteElements(int arr[],int position,int n)
{
    for(int i=position;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
}
int main()
{
    int arr[]={2,4,4,4,6,4,8,5,4,2};
    int item;
    cout<<"Enter deleting elements: ";
    cin>>item;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            DeleteElements( arr,i,n);
            n--;
            i--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
