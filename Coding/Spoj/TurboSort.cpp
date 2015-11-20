#include<iostream>
using namespace std;
void merge(int low,int mid,int high,int a[]);
void divide(int low,int high ,int a[] )
{    int mid;
     if(low<high){
      mid=(low+high)/2;
      divide(low,mid,a);
      divide(mid+1,high,a);
      merge(low,mid,high,a);

        }
}
void merge(int low,int mid,int high,int a[])
{  int l,m,c,k;
   l=low;
   m=mid+1;
   while(l<low&&m<high){
    if(a[l]>a[m]){
    c[k]=a[m];
    m++; k++;

   }

    else{
        c[k]=a[l];
        l++;
        k++;
    }}
    while(l<low){
        c[k]=a[l];
        l++;k++;
    }
    while(m<high){
        c[k]=a[m];
        m++;k++;
    }


}
int main(){
int a[100];
int n,i;
cin>>n;
for(i=0;i<n;i++){
    cin>>a[i];
}
divide(0,n-1,a[])

for(i=0;i<n;i++){ cout<<a[i]; }
return 0;
}
