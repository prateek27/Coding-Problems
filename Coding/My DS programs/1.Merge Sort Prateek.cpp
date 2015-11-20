#include<iostream>
using namespace std;

//Merge Sort by Prateek .
void partition(int a[],int low,int high);
void mergeSort(int a[],int low,int mid,int high);

int main(){
int n,a[100],i;

cout<<"Enter N ";
cin>>n;

for(i=0;i<n;i++)
{ cin>>a[i];  }

partition(a,0,n-1);

for(i=0;i<n;i++)
{ cout<<a[i];    }

return 0;
}

void partition(int a[],int low,int high){
if(low<high)
{
    int mid=(low+high)/2;

    partition(a,low,mid);
    partition(a,mid+1,high);
    mergeSort(a,low,mid,high);
}
}

void mergeSort(int a[],int low,int mid,int high){
int l=low;
int i=low;
int m=mid+1;
int k,temp[100];
while(l<=mid&&m<=high){
    if(a[i]<a[m])
    { temp[i]=a[l];
    i++;
    l++;
    }
    else
    {
        temp[i]=a[m];
        m++;
        i++;
    }
   }
while(l<=mid)
{
    temp[i++]=a[l++];
}
while(m<=high){
    temp[i++]=a[m++];}

for(k=low;k<=high;k++)
{ a[k]=temp[k];}


}


