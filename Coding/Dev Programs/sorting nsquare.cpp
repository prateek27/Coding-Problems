#include<iostream>
using namespace std;

int main()
{
    //Bubble Sort.
    
    int a[50],i,n,key,j;
    
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the list of elements "<<endl;
    
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    }
    int temp;
    
    
    
    for(i=1;i<n;i++)
    {
     key=a[i];
     j=i-1;
      while(a[j]>key&&j>=0)
      {
      temp=key;
      a[j+1]=a[j];
      a[j]=temp;
       j--;
      }
     
    }
    cout<<endl<<"The sorted list in Ascending Order is :"<<endl;
    
    
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<"\t";
    }
    system("pause");    
    return 0;
    
}
