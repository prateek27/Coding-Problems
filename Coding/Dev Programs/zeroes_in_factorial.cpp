#include<iostream>
      
using namespace std;

int main()
{
    int num,i,j=5,temp,sum=0 ;
    cout<<"This program tells you the zeroes in factorial of any number "<<endl<<endl; 
    cout<<"Enter the Number : ";
    cin>>num;
    
    while(temp!=0)
    {
                 temp=num/j;
                 j=j*5;
                 sum=sum+temp;
    }
    
cout<<endl<<"The zeroes in "<<num<<"! are "<<sum<<endl<<endl;

system("PAUSE");
return 0;
}
