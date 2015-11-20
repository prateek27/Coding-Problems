#include<iostream>
using namespace std;

int main()
{
     
    int i,j,a[5][5];
    int m,n;
    cout<<"Enter the value of m and n "<<endl;
    cin>>m>>n;
    cout<<"Enter the elements of "<<m<<"X"<<n<<" matrix"<<endl;
    for(i=0;i<m;i++)
    {
               for(j=0;j<n;j++)
               {
                               cin>>a[i][j];
                                     }
               
}
cout<<"The entered matrix is "<<endl;

 for(i=0;i<m;i++)
    {
               for(j=0;j<n;j++)
               {
                               cout<<a[i][j];
                               cout<<"\t ";
                               }
               cout<<endl;
}
system("PAUSE");
return 0;
}
