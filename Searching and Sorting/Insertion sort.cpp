#include<bits/stdc++.h>
using namespace std;
void inserction(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key_value = arr[i];
        int j =i-1;
        while(j>=0 && arr[j]>key_value)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key_value;
    }
}
int main()
{
    int arr[]={2,6,8,9,1,23,4,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    inserction(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

