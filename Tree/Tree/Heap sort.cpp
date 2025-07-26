#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n ,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest !=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
       heapify(arr,n,i);
    }
    for(int j=n-1;j>=1;j--)
    {
        swap(arr[j],arr[0]);
        heapify(arr,j,0);
    }

}
int main()
{
    int arr[]={2,4,6,8,34,12,89};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before heapsort:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);
    cout<<"After heapsort:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
