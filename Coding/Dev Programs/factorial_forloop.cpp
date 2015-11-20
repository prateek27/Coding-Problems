#include<iostream>
using namespace std;

int main()
{
int i,number,temp=1;
long int fact;
cout<<"To calculate the factorial enter the no.";
cin>>number;
for(i=1;i<=number;i++)
{
    fact=temp*i;
    temp=fact;
}
cout<<"The factorial of given number is "<<fact<<endl;  
    
    
    
  system("PAUSE");
  return 0;
  
}
