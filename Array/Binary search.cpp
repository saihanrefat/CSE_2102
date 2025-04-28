#include<iostream>
using namespace std;
int main()
{
    int arr[12]={11,22,30,40,44,55,60,66,77,80,88,99};
    int left,right,middle,item;
    left=0;
    right=sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter searching item: ";
    cin>>item;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(arr[middle]==item)
        {
            cout<<middle;
            return 0;
        }
        else if(arr[middle]<item)
        {
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }
    cout<<"Item Not found"<<endl;
}

