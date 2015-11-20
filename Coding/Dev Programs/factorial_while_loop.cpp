#include<iostream>
using namespace std;

int main()
{
int i=1,number,temp=1;
long int fact;
cout<<"To calculate the factorial enter the no.";
cin>>number;
while(i<=number)
{
    fact=temp*i;
    temp=fact;
    i++;
}
cout<<"The factorial of given number is "<<fact<<endl;  
    
    
    
  system("PAUSE");
  return 0;
  
}
