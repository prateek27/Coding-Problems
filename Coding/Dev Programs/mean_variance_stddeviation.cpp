#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    //Find mean ,Variance and standard deviation of N elements
    
    int i,n;
    float mean,var,sd,a[100],sum=0;
    cout<<"Enter the number of elements you want to enter : ";
    cin>>n;
    
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
                 sum=sum+a[i];
    }
    
    mean=sum/n;
    
    float temp=0;
    for(i=0;i<=n;i++)
    {
      temp = temp+ (a[i]-mean)*(a[i]-mean);
    }
    
    var=temp/n;
    sd=sqrt(var);
    
    
    cout<<" Mean is "<<mean<<endl;
    cout<<" Variance is "<<var<<endl;
    cout<<" Standard Deviation is "<<sd<<endl;
    
    
    
    system("PAUSE");
    return 0;
    
}
   
     
