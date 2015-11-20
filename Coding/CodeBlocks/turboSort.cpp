#include<iostream>
using namespace std;

void mergeSort(int a[],int,int,int);
//PARTITON FUNCTION TO DIVIDE----------------------------------------------------------------------
void partition(int a[],int low, int high){
int mid;
if(low<high){
   mid=(low+high)/2;
    partition(a,low,mid);
    partition(a,mid+1,high);
    mergeSort(a,low,mid,high);

    } }

void mergeSort(int a[],int low,int mid,int high){

    int i,m,k,l,temp[100];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(a[l]<=a[m]){
             temp[i]=a[l];
             l++;
         }
         else{
             temp[i]=a[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=a[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=a[k];
             i++;
         }
    }

    for(k=low;k<=high;k++){
         a[k]=temp[k];
    }
}



//MAIN FUNCTION --------------------------------------------------------------------
int main(){
int i,n, a[100];
cin>>n;
for(i=0;i<n;i++){
cin>>a[i];
}


partition(a,0,n-1);
for(i=0;i<n;i++){
cout<<a[i]<<endl;
  }
 return 0;
}
