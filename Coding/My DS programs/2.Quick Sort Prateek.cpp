#include<iostream>
using namespace std;

//Quick Sort by Prateek
void quickSort(int a[],int p,int r);
int partition(int a[],int ,int);

int main(){
int n,a[100],i;

cout<<"Enter N ";
cin>>n;

for(i=0;i<n;i++)
{ cin>>a[i];  }

quickSort(a,0,n-1);

for(i=0;i<n;i++)
{ cout<<a[i]<<" ";  }

return 0;
}

void quickSort(int a[],int p,int r){
if(p<r)
 {
    int q = partition(a,p,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
 }
}

int partition(int a[],int p,int r)
{   int j,temp;
    int x = a[r];  // x is the pivot element
    int i=p-1;
    for(j=p;j<r;j++)
    {
        if(a[j]<x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;

return i+1;
}

