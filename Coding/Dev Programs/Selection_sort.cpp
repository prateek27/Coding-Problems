#include<iostream>
using namespace std;

int main()
{
    //Selection Sort.Bring the minmum element from the remaining unsorted list to the foremost position.
    int a[50],i,n,min,j;
    
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the list of elements "<<endl;
    
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    }
    int temp;
    
    
    
    for(i=0;i<n;i++)
    { 
      min=i;
      for(j=i+1;j<=n;j++)
      {
       if(a[j]<a[i])
       {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;                             
       }             
     
    }}
    cout<<endl<<"The sorted list in Ascending Order is :"<<endl;
    
    
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<"\t";
    }
    system("pause");    
    return 0;
    
}
