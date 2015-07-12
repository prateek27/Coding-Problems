#include<iostream>
using namespace std;

void insertionSort(int *a,int n){
int i,j;

for(int i=1;i<n;i++){
{       j=i-1;
        int key = a[i];
        while(a[j]>key&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}


return ;
}

void print(int *a,int n){

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}

int main(){
int a[] = {5,-9,-1,3,2};
int n = sizeof(a)/sizeof(n);
insertionSort(a,n);
print(a,n);
return 0;
}

