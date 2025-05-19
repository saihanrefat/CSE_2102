#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high-1];
    int j=-1;
    for(int i=0;i<high;i++)
    {
        if(arr[i]<pivot)
        {
            j=j+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[high-1],arr[j+1]);
    return j+1;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi);
        quicksort(arr,pi+1,high);

    }
}
int main()
{
    int arr[]={44,33,11,55,77,90,40,60,99,22,88,66};
    int size=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
