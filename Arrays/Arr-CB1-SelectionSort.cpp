#include<iostream>
using namespace std;

void selectionSort(int *a,int n){
int i,j;
//Select min and put it at first
int min_index=0;

for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){

        if(a[j]<a[min_index])
            { min_index=j; }

    }
    swap(a[i],a[min_index]);
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
selectionSort(a,n);
print(a,n);
return 0;
}


