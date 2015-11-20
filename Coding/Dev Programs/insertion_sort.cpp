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
       a[j+1]=a[j];
       j--;
      }
     a[j+1]=key;
    }
    cout<<endl<<"The sorted list in Ascending Order is :"<<endl;
    
    
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<"\t";
    }
    //Binary Search
             int value;
              cout<<endl<<"Enter the value to be searched";
              cin>>value;
              
             int low=0;
             int high=n-1;
             int mid;
             
             mid=(high+low)/2;
             while(low<=high)
             {
                             
                             if(value==a[mid])
                             {
                             cout<<"Element found at postion "<<mid+1;
                             break;               //Note the use of break 
                             }
                             else if(value>a[mid])
                             {
                                  low=mid+1;
                                  }
                              else
                              {
                                  high=mid-1;
                              } 
                              mid=(high+low)/2;
             };
    
    system("pause");          
    
    return 0;
    
}
