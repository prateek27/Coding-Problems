#include<iostream>
using namespace std;

int main()
{
    //Bubble Sort.Take the bigger elements to the last position.
    
    int a[50],i,n,current,j;
    
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
    for(j=i;j<n;j++)
    {
      if(a[i]<a[j])
      {
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
       }
    }}
    cout<<endl<<"The sorted list in Descending Order is :"<<endl;
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<"\t";
}
    system("pause");    
    return 0;
    
}
