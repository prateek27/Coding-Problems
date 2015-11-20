#include<iostream>
using namespace std;

int main()
{
    /* Program to check whether is given number is odd or even 
    without using modulus function. It involves checking for 
    least significant bit (LSB) in its binary representation */
    
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    
    if((num&1)==0)
    cout<<num<<" is even "<<endl;  
    
    else
    cout<<num<<" is odd"<<endl ;
    
    system("PAUSE");
    return 0;
    
}
