#include<iostream>
using namespace std;

void quickSort(int a[],int p,int r);
int partition(int a[],int p,int r);

int main(){
int a[100];
int i,n;
cout<<"No of elements";
cin>>n;

for(i=0;i<n;i++) cin>>a[i];
cout<<"Calling QuickSort";
quickSort(a,0,n);
for(i=0;i<n;i++) cout<<a[i];

return 0;
}

void quickSort(int a[],int p,int r){

int q;
if(p<r){
q = partition(a,p,r);
quickSort(a,p,q-1);
quickSort(a,q+1,r);
    }
}

int partition(int a[],int p,int r){
int x=a[r];
int i=p-1;
for(int j=p;j<r;j++)
{ if(a[j]<x)


   i++;
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;  }

int temp2=a[r];
a[r]=a[i+1];
a[i+1]=temp2;
return i+1;
}
