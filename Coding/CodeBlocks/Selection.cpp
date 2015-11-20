// Selection Sort
#include<iostream>
using namespace std ;

/*void exchange( int *a,int *b ){
int *temp;
temp=a;
a=b;
b=temp;
}*/


int main(){
    int n,a[50],i,j,iMin;
cout<<" Enter number of elements :"<<endl;
cin>>n;
cout<<"Enter the elements";
for(i=0;i<n;i++){

    cin>>a[i];
}

for(i=0;i<n-1;i++)
{
    iMin=i;
  for(j=i+1;j<n;j++){
    if(a[j]<a[iMin])
    {
        iMin = j ;          //Remeber its index of min element
    }

  }
    int temp;
    temp=a[i];
    a[i]=a[iMin];
    a[iMin]=temp;


}
  cout<<"The Sorted Array using Selection  sort is : ";
for(i=0;i<n;i++){
  cout<<a[i]<<"\t";

}


return 0;
}
