#include<bits/stdc++.h>
using namespace std;
void selection(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int small_index =i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[small_index])
            {
                small_index=j;
            }
        }
        int temp=arr[i];
        arr[i]= arr[small_index];
        arr[small_index]=temp;
    }
}
int main()
{
    int arr[]={2,6,8,9,1,23,4,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
