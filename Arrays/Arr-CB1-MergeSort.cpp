#include<iostream>
using namespace std;

void merge(int *a,int low,int mid,int high);

void mergeSort(int *a,int low,int high){

if(low<high){
    int mid=  low + (high-low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
    }
return ;
}

void merge(int *a,int low,int mid,int high){
int *temp = new int[high+1];

int l=low;
int m = mid+1;
int h = high;
int i=low;

while(l<=mid&&m<=high){

    if(a[l]<a[m]){
        temp[i++] = a[l++];
    }
    else{
        temp[i++] = a[m++];
    }

}

//Mistake 1 . l!=mid
while(l<=mid){
    temp[i++] = a[l++];
}
while(m<=high){
    temp[i++] = a[m++];
}

for(i=low;i<=high;i++){
    a[i] = temp[i];
}

return;
}

void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int a[] = { 5,7,8,9,10,2,45,6 };
int n = sizeof(a)/sizeof(int);
mergeSort(a,0,n-1);
print(a,n);
return 0;
}
