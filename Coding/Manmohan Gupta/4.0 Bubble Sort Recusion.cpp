#include<iostream>
using namespace std ;

//Bubble Sort using Recursion !

void bubbleSort(int a[100],int n){
    int temp;
for(int i=0;i<n;i++){
    if(a[i]>a[i+1])
    {
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }}

    if(n>=2)
    bubbleSort(a,n-1);

    }


int main(){
int a[100],n;
cout<<"Enter Number of elements :";
cin>>n;

cout<<"Enter the elements "<<endl;
for(int i=0;i<n;i++)
    cin>>a[i];

bubbleSort(a,n);

for(int i=0;i<n;i++){
    cout<<a[i]<<" " ;
}
return 0;
}
