#include<iostream>
using namespace std;

int main()
{
    //Program to check leap year or not.
    
int year;
cout<<"Enter a year ";
cin>>year;

if(((year%4==0)&&(year%100!=0))||(year%400==0))
cout<<year<<" is a leap year "<<endl           ;

else
cout<<year<<" is not a leap year "<<endl;

system("PAUSE");
return 0;
}
