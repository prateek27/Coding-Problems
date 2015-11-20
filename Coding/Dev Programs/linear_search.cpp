#include<iostream>
using namespace std;

int main()
{
    
    int i,a[50],key,n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    cout<<"Enter the list of elements "<<endl;
    
    int position=0;
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
    }
    cout<<"Enter the element to be searched "<<endl;
    cin>>key;
    
    for(i=0;i<n;i++)
    {
     if(key==a[i])
     {
       position=i+1;
       break;}
    
     }
     
     
     if(position)
     cout<<"Element found at position "<<position<<endl;
     else
     cout<<"Element not found "<<endl;
          
    
system("PAUSE");
return 0;

}
