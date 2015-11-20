#include<iostream>
using namespace std;
int bsearch(int a[],int , int ,int);
int main(){
    int i,n,x=0,a[100],num;
    cout<<"Enter number of numbers ";
    cin>>n;
    cout<<"Enter the numbers ";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<endl<<"Enter the element to be searched ";
    cin>>num;
    x=bsearch(a,0,n-1,num);

    cout<<"Element found at position "<<x+1;
    return 0;
}

int bsearch(int a[100],int low,int high,int key){
 int mid;
 if(low<=high){
 mid=(high+low)/2;

 if(key==a[mid])
    return mid;

 else if(key>a[mid]){
      return  bsearch(a,mid+1,high,key);
          }
 else if(key<a[mid])
    return bsearch(a,low,mid,key);

 }

}
