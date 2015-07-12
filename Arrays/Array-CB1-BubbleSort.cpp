#include<iostream>
using namespace std;

void bubbleSort(int *a,int n){
int i,j;

for(int i=0;i<n-1;i++){
    for(int j=1;j<n;j++){
        if(a[i]>a[j])
            swap(a[i],a[j]);
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
bubbleSort(a,n);
print(a,n);
return 0;
}


