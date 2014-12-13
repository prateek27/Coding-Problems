#include<iostream>
using namespace std;

int partition(int *a,int low,int high);
void quickSort(int *a,int low,int high){
    if(low<high){
    int p=partition(a,low,high);
    quickSort(a,low,p-1);
    quickSort(a,p+1,high);
    }
}

int partition(int *a,int low,int high){
    int i;
    int j=low-1;
    int pivot = a[high];
    for(i=low;i<high;i++){
        if(a[i]<pivot){
            j++;
            swap(a[i],a[j]);
        }

    }
    swap(a[j+1],a[high]);
    return j+1;
}
void print(int *a,int n){

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}
int main(){
int a[] = {5,-9,-1,3,2};
int n = sizeof(a)/sizeof(n);
quickSort(a,0,n-1);
print(a,n);
return 0;
}
