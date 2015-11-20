#include<iostream>
using namespace std;

long factorial(int);

int main()
{
    int i,j,k,n,answer;
    cout<<"Enter the no. of rows you want to see in Pascal's Triangle";
    cin>>n;
    
    for(i=0;i<n;i++)
    {
          for(j=n-i;j>=1;j--)
          {
          cout<<" ";
          }
          for(k=0;k<=i;k++)
          {
          answer=factorial(i)/(factorial(i-k)*factorial(k));
          cout<<answer<<" ";
          }
          cout<<endl;
          
}

system("PAUSE");
return 0;
}

long factorial(int n)
{
    int d;
     long factorial=1;
     for(d=1;d<=n;d++)
     {
                 factorial=factorial*d;
                   }               
 return(factorial);
 }     

                     
    
