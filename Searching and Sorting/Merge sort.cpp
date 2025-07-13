#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int arr1[r-l+1];
    int k=0;
    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
        {
           arr1[k]=arr[i];
           k++;i++;

        }
        else
        {
            arr1[k]=arr[j];
           k++;j++;
        }
    }
    while(j<=r)
    {
        arr1[k]=arr[j];
        k++;j++;
    }
    while(i<=m)
    {
        arr1[k]=arr[i];
        k++;i++;
    }
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {
        arr[i]=arr1[i];
    }
}
void divide(int arr[],int l,int r)
{

    if(l<r)
    {
       int m=(l+r)/2;
        divide(arr,l,m);
        divide(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    int arr[]={2,6,8,9,1,23,4,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    divide(arr,0,n);
    cout<<endl<<"After sorting :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


}

