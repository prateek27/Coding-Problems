#include<iostream>
using namespace std;

void heapSort(int a[],int n);
build_max_heap(int a[],int n);
void maxHeapify(int a[],int i);
//HeapSort Sort by Prateek
int heapsize;
int main(){
int n,a[100],i;

cout<<"Enter N ";
cin>>n;
heapsize=n;

for(i=1;i<=n;i++)
{ cin>>a[i];  }

heapSort(a,1,n);

for(i=1;i<=n;i++)
{ cout<<a[i]<<" ";  }

return 0;
}

void heapSort(int a[],int n)
{
int temp;
build_max_heap(a,n);
    for(i=n;i>=2;i--)
        {
            temp=a[i];
            a[i]=a[1];
            a[1]=temp;

            heapsize--;
            maxHeapify(a,1);
        }
}

build_max_heap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        maxHeapify(a,i);
}

void maxHeapify(int a[],int i)
{ int temp;
 int l=2*i;
 int r=2*i+1;
 int largest = i ;
 if(l<=heapsize&&a[l]>a[largest])
 largest=l;
 if(r<=heapsize&&a[r]>a[largest])
 largest=r;

if(largest!=i){
    temp=a[largest];
    a[largest]=a[i];
    a[i]=temp;

    maxHeapify(a,i)
}
}
