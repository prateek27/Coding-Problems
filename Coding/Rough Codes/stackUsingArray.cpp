PROGRAM 1: To implement stack using array .
#include<iostream>
using namespace std;
void push(int [],int ,int &);
int pop(int [],int &);
void show(int [],int);
const int size=5;
int main()
{
  int arr[size],a,re,item;
  int top=-1;
  char ch;
  do
  {
    cout<<"Enter the operation you want to perform in the stack\n1.Insert\n2.Delete\n3.Display"<<endl;
    cin>>a;
    switch(a)
    {
        case 1: cout<<"Insert the element in the stack"<<endl;
        cin>>item;
        push(arr,item,top);
        break;
        case 2:
        re=pop(arr,top);
        break;
        case 3: cout<<"Contents of stack are:-\n";
        show(arr,top);
        break;
        default: cout<<"Invalid operation"<<endl;
        break;
    }
   cout<<"Do you want to perform more operations\n";
   cin>>ch;
  }while(ch=='y'||ch=='Y');
return 1;
}
void push(int a[],int item,int &t)
{
   if(t==size-1)
       {
            cout<<"Stack overflow\n";
       }
        else
        {
            t++;
            a[t]=item;
        }
}
int pop(int a[],int &t)
{
     int ret;
     if(t==-1)
     {
       cout<<"Stack underflow\n";
     }
     else
     {
        ret=a[t];
        t--;
     }
     return ret;
}
void show(int a[],int t)
{
     int i;
     for(i=t;i>=0;i--)
     {
       cout<<a[i]<<endl;
     }
}

