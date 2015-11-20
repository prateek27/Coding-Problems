// Bubble Sort
#include<iostream>
using namespace std ;

void swap( int *a,int *b ){
int temp;
temp=*a;
*a=*b;
*b=temp;
}


int main(){
    int n,a[50],i,j,iMin;
cout<<" Enter number of elements :"<<endl;
cin>>n;
cout<<"Enter the elements";
    for(i=0;i<n;i++){
    cin>>a[i];
}

for(i=1;i<n;i++){

    for(j=1;j<=n-i;j++)
     {
         if(a[j]<a[j-1])
            swap(&a[j],&a[j-1]);
     }

}




  cout<<"The Sorted Array using Bubble sort is : ";
for(i=0;i<n;i++){
  cout<<a[i]<<"\t";

}


return 0;
}
