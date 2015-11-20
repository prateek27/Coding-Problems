#include<iostream>
using namespace std;

int main()
{
    int i,j,a[3][3],b[3][3],c[3][3],k,temp=0;
    int row1,col1,row2,col2;
    
    cout<<"Enter the rows & columns of first matrix "<<endl;
    cin>>row1>>col1;
    
    cout<<"Enter the rows & columns of second matrix "<<endl;
    cin>>row2>>col2;
    
   
    if(col1==row2)
    {
    cout<<"Enter the elements of first matrix"<<endl;
       for(i=0;i<row1;i++)
    {
               for(j=0;j<col1;j++)
               {
                               cin>>a[i][j];
                                     }
                                     }  
         cout<<"Enter the elements of second matrix"<<endl;
         for(i=0;i<row2;i++)
    {
               for(j=0;j<col2;j++)
               {
                               cin>>b[i][j];
                                     }
    
}
    
    
 cout<<"The entered matrices are "<<endl;   
 for(i=0;i<row1;i++)
    {
               for(j=0;j<col1;j++)
               {
                               cout<<a[i][j];
                               cout<<"\t ";
                               }
               cout<<endl;
               
}             
     cout<<endl;   

 for(i=0;i<row2;i++)
    {
               for(j=0;j<col2;j++)
               {
                               cout<<b[i][j];
                               cout<<"\t ";
                               }
cout<<endl;   
}               
cout<<"The product of matrices is "<<endl;
for(i=0;i<row1;i++)
{
                   for(j=0;j<col2;j++)
                   {
                                      c[i][j]=0;
                                      temp=0;   //These two steps are important.Dont skip . A big mistake.
                                      for(k=0;k<col1;k++)
                                       { 
                                      temp=temp+a[i][k]*b[k][j];
                                      c[i][j]=temp;
                                      
                                      }
                                      
                   
                                     
                                      
                                      }
                        }


for(i=0;i<row1;i++)
{
                   for(j=0;j<col2;j++)
                   {
                    cout<<c[i][j];
                    cout<<"\t ";
                   }
cout<<endl;
}

}
else
{
    cout<<"Multiplication Not possible"<<endl;
}


system("PAUSE");
return 0;
}
