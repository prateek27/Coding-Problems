#include<iostream>
using namespace std;

int main()
{
    //Diagonally add elements of a matrix 
    int i,j,sum=0,a[3][3];
    
    cout<<"Enter the elements of 3x3 matrix"<<endl;
    for(i=0;i<3;i++)
    {
               for(j=0;j<3;j++)
               {
                               cin>>a[i][j];
                                     }
               
}
cout<<"The entered matrix is "<<endl;

 for(i=0;i<3;i++)
    {
               for(j=0;j<3;j++)
               {
                               cout<<a[i][j];
                               cout<<" ";
                               }
               cout<<endl;
}


 for(i=0;i<3;i++)
    {
               for(j=0;j<3;j++)
               {
                               if(i==j)
                               {sum=sum+a[i][j];}
                               }
               
}
cout<<"The sum of diagonal elements is "<<sum<<endl;


system("PAUSE");
return 0;
}
