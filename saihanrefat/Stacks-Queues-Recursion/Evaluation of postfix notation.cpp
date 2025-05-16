#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 100
using namespace std;
int stack[max];
int top=-1;
void push(int value)
{
    if(top>=max-1)
    {
        cout<<"overflow"<<endl;
        return;
    }
    else
    {
        top=top+1;
        stack[top]=value;
    }
}
int pop()
{
    if(top<0)
    {
        cout<<"Underflow";
        return 0;
    }
    else
        return stack[top--];
}
int eva_postfix(char *ptr)
{
    char *temp;
    temp=strtok(ptr," ");
    while(temp !=NULL)
    {
        if(isdigit(temp[0])|| (temp[0]=='-')&& isdigit(temp[1]))
        {
            push(atoi(temp));
        }
        else
        {
            int a= pop();
            int b=pop();
            int result;
            if(temp[0]=='+')
            {
                result=a+b;
            }
            else if(temp[0]=='-')
            {
                result=a-b;
            }
            else if(temp[0]=='*')
            {
                result=a*b;
            }
            else if(temp[0]=='/')
            {
                result=a/b;
            }
            else
            {
                cout<<"Invalid operator";
                return 0;
            }
             push(result);
        }
        temp=strtok(NULL," ");
    }
    return pop();
}
int main()
{
    char ptr[100];
    fgets(ptr,sizeof(ptr),stdin);
    ptr[strcspn(ptr,"\n")]='\0';
    int result=eva_postfix(ptr);
    cout<<result;
    return 0;
}
