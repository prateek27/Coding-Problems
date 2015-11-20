#include<iostream>
using namespace std;

int main()
{   
    int i,range,sum=0 ;    
    cout<<"Enter the range from 1 to __ " ;
    cin>>range; 
    
    for(i=1;i<=range;i++)
    {
     if(i%2==1)
     sum=sum+i;
     
     else
     continue;
     }
cout<<"The sum of odd numbers upto "<<range<<" is "<<sum<<endl;     
system("PAUSE");
return 0;
}
