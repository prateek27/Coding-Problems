#include<iostream>
using namespace std;

int main()
{
    /* Program to find reverse of a given number */
    
    int num,reverse=0,temp;
    cout<<"Enter a number : ";
    cin>>num;
    
    while(num!=0)
    {
     temp=num%10;
     num=num/10;
     reverse=reverse*10+temp;
     
    
    
}
cout<<"The reversed number is "<<reverse<<endl;
system("PAUSE");
return 0 ;
}
