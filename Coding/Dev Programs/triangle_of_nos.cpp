#include<iostream>
using namespace std ;

int main()
{
    int i,j,k,n;
    
    cout<<"Enter the no. of rows you want to see ";
    cin>>n;
    
    for(i=1;i<=n;i++)
    { 
                    cout<<endl;
                    for(j=n-i;j>0;j--)
                    { 
                    cout<<" "  ;
                     }
                     
                    for(k=1;k<=i;k++)
                    {
                    cout<<k;
                    }
                    
                    for(k=i-1;k>=1;k--)
                    {
                    cout<<k;
                    }
     }
     cout<<endl<<endl;
    system("PAUSE");
    return 0;
    
}
