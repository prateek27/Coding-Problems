#include<iostream>
using namespace std;
int partition(int *a,int low,int high);

void quickSort(int *a,int low,int high){

if(low<high){
    int p = partition(a,low,high);
    quickSort(a,low,p-1);
    quickSort(a,p+1,high);
}
return;
}

int partition(int *a,int low,int high){
int i=low;
int j=low-1;

int pivot = a[high];

    for(int i=low;i<high;i++){
        if(a[i]<pivot){
            swap(a[++j],a[i]);
        }
    }
    swap(a[j+1],a[high]);

return j+1;
}


void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int a[] = { 5,7,8,9,10,2,45,6 };
int n = sizeof(a)/sizeof(int);
quickSort(a,0,n-1);
print(a,n);
return 0;
}

