// Insertion Sort
#include<iostream>
using namespace std ;

int main(){
    int n , a[50],i,j,key;
cout<<"Enter number of elements "<<endl;
cin>>n;
cout<<"Enter the elements";
for(i=0;i<n;i++){

    cin>>a[i];
}
for(i=1;i<n;i++)
{ key=a[i];
  j=i-1;
  while(j>0&&a[j]>key)
  {
      a[j+1]=a[j];
      j=j-1;
      a[j+1]=key;
  }

}
  cout<<"The Sorted Array using insertion sort are : ";
for(i=0;i<n;i++){
  cout<<a[i]<<"\t";

}


return 0;
}
