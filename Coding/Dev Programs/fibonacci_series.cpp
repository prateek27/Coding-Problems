#include<iostream>
using namespace std;

int main()
{
    //Fibonacci Series //
    
    int i,x=0,y=1,z,n;
    cout<<"Enter the number of elements you want in fibonacci series ";
    cin>>n;
    
    cout<<endl<<x<<"\t"<<y;
    
    for(i=1;i<n-1;i++)
    {
     z=x+y;
     x=y;
     y=z;
     cout<<"\t"<<z;
     }
     cout<<endl<<endl;
     
     
     system("PAUSE");
     return 0;
     }
