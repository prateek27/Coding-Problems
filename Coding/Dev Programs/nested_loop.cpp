#include<iostream>
using namespace std;

int main()
{
int n,i,j;
cout<<"Enter the no. of line of stars you want to see ";
cin>>n;
for(i=1;i<=n;i++)
{cout<<endl;
     for(j=1;(j<=i);j++)
     cout<<"*";
     }
    cout<<endl;
    
    
  system("PAUSE");
  return 0;
  
}
