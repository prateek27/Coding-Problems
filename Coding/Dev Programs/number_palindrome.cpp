#include<iostream>
using namespace std;

int main()
{
    /* Program to find reverse of a given number */
    
    int num,reverse=0,temp,var;
    
    cout<<"Enter a number : ";
    cin>>num;
    var=num; //This is done to preserve the orignal number for comparison . 
    while(var!=0)
    {
     temp=var%10;
     var=var/10;
     reverse=reverse*10+temp;
     }
  
    
cout<<"THe reverse of "<<num<<" is "<<reverse<<endl;
if(reverse==num)
{
cout<<"The number is a palindrome "<<endl;
}
else
{
    cout<<"The number is NOT a palindrome "<<endl;
}

system("PAUSE");
return 0 ;
}
