#include<iostream>
using namespace std;


//Iterative Version of Heap Sort
int main()
{
int n,largest,root,temp,i;
cout<<"Enter the number of elements";
cin>>n;
int heap[n];

for(i=0;i<n;i++)
{cin>>heap[i];}
for(i=1;i<n;i++)
{ largest=i;
  do{
  root=(largest-1)/2;
  if(heap[root]<heap[largest])
  { temp=heap[root];
    heap[root]=heap[largest];
	heap[largest]=temp;
  }
  largest=root;
}
while(largest!=0);
}

cout<<"Heap Array";
for(i=0;i<n;i++) cout<<heap[i];

return 0;
}
