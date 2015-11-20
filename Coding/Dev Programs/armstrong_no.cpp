#include<iostream>
using namespace std;

int main()
{
    //Program to check a Armstrong No. - Number which is equal to sum of cubes of its digits .For eg 153 "//
    
    int num,sum=0,temp,var;
    cout<<"Enter a number :";
    cin>>num;
    temp=num;
    while(temp!=0)
    {
             var=temp%10;
             temp=temp/10;
             sum=sum +var*var*var;
    } 
    
    if(sum==num)
    cout<<"Armstrong No."<<endl;
    
    else
    cout<<"Ordinary No." <<endl;
    
    system("PAUSE");
    return 0;
}
