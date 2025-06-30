#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest =i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<n && arr[left]> arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[right]> arr[largest])
    {
        largest=right;
    }
    if(i !=largest)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
int main()
{
    int arr[]={23,9,15,6,14,40};
    int n=6;
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,6,i);
    }
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
}
