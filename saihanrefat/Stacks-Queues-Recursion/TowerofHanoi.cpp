
#include<iostream>
using namespace std;
void TowerofHanoi(int n,char begin,char end,char aux)
{
    if(n==1)
    {
        cout<<n<<". Disks move from "<<begin<<" to "<<end<<endl;
        return;
    }
    TowerofHanoi(n-1, begin, aux, end);
    cout<<n<<". Disks move from " << begin <<" to " << end <<endl;
    TowerofHanoi(n-1, aux, end, begin);
}
int main()
{
    int n;
    cout<<"Enter disks number: ";
    cin>>n;
    TowerofHanoi(n,'a','b','c');
}
