#include<iostream>
using namespace std;



int main()
{
    int i,j,m,n,a[10],b[10],c[20],l,h,temp;
    
    cout<<"Enter the no.of elements in First array (max 10) ";
    cin>>m;
    cout<<endl<<"Enter elements :"<<endl;
    for(i=0;i<m;i++)
    {
                    cin>>a[i];
    }
    
    
    for(i=0;i<m;i++)
    {
    for(j=0;j<m-1;j++)
    {
          if(a[j]>a[j+1])
          {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
          }
     }} 
     
     cout<<"The sorted list is "<<endl ;  
     for(i=0;i<m;i++)
     cout<<a[i]<<"  ";
     
     cout<<endl<<"Enter the no.of elements in Second array (max 10) ";
    cin>>n;
    cout<<endl<<"Enter elements :"<<endl;
    for(i=0;i<n;i++)
    {
                    cin>>b[i];
    }
    
    temp=0;
    for(i=0;i<n;i++)
    {
    for(j=0;j<n-1;j++)
    {
          if(b[j]>b[j+1])
          {
          temp=b[j];
          b[j]=b[j+1];
          b[j+1]=temp;
          }
     }} 
     
     cout<<"The sorted list is "<<endl ;  
     for(i=0;i<n;i++)
     cout<<b[i]<<"  ";
     
     
     cout<<endl<<"The merged array is ";
     
     i=j=h=0;
     while(i<m||j<n)
     {
         if(a[i]<b[j])
         {
         c[h]=a[i];
         i++;
         }
         else 
         {
         c[h]=b[j];
         j++;
         }
         h++;
     }
     if(i==m)
     { 
             for(l=j;l<n;l++)
             {
              h++;                 
             c[h]=b[l];
             
             }
     }  
     if(j==n)
     { 
             for(l=i;l<m;l++)
             {
              h++;               
             c[h]=a[l];
             
             }
     } 
       
      for(i=0;i<m+n;i++)
     {
     cout<<c[i]<<" ";
     }
     cout<<endl<<endl;
     system("PAUSE");
     return 0;
     }  


