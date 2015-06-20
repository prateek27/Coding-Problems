#include<iostream>
using namespace std;


void recursiveReverse(int *a,int low,int high){
if(low>high)
    return;

    swap(a[low],a[high]);
    recursiveReverse(a,low+1,high-1);

}

void print(int *a,int n){
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
}
int main(){
int a[]={1,2,3,4,5};
int n=sizeof(a)/sizeof(int);
recursiveReverse(a,0,n-1);
print(a,n);
return 0;
}
