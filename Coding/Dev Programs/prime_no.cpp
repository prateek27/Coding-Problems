#include<iostream>  
using namespace std;

int main()
{
    //Program to check given no. is prime or not 
    
    int i,n,flag=0,temp;
    
    cout<<"Enter a number : ";
    cin>>n;
    
    for(i=2;i<=n/2;i++)
    {
          temp=n%i;
          if(temp==0)
          {
          flag=1;
          break;
          }
          else
          {
              continue;
          }
    }
          
          
          if(flag==1)
          cout<<n<<" is not prime a number. "<<endl;
          else
          cout<<n<<" is a prime number "<<endl;
          
    
    system("PAUSE");
    return 0;
    
}
