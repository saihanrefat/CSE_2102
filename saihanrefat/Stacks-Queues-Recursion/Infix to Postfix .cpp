
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
using namespace std;
int stack[max];
int top=-1;
void push(int val)
{
    if(top>=max-1)
    {
        cout<<"OVERFLOW"<<endl;
        return;
    }

        top=top+1;
        stack[top]=val;
}
int pop()
{
    if(top<0)
    {
        cout<<"UNDERFLOW"<<endl;
        return 0;
    }
    else
    {
        return(stack[top--]);
    }
}
int precedence(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch== '/')
    {
        return 2;
    }
    else if(ch=='+' || ch== '-')
    {
        return 1;
    }

}
int infix_to_postfix(char infix[],char postfix[])
{
    int j=0,i;
    char ch;
    for(i=0;infix[i];i++)
    {
        ch=infix[i];
        if(isspace(ch))
        {
            continue;
        }
        if(isalnum(ch))
        {
            postfix[j++]=ch;
            postfix[j++]=' ';
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(top !=-1 && stack[top] !='(')
            {
                postfix[j++]=pop();
              postfix[j++]=' ';
            }
            pop();
        }
        else{
            while(top !=-1 && precedence(ch)<=precedence(stack[top]))
            {
                 postfix[j++]=pop();
               postfix[j++]=' ';
            }
            push(ch);
        }
    }
    while(top !=-1)
    {
         postfix[j++]=pop();
              postfix[j++]=' ';
    }
    postfix[j]='\0';
}
int main()
{
    char infix[100],postfix[100];
    fgets(infix,sizeof(infix),stdin);
    infix[strcspn(infix,"\n")]='\0';
    infix_to_postfix(infix,postfix);
   cout<<postfix;

}
