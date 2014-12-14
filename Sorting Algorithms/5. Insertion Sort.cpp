#include<iostream>
using namespace std;

//---------------------------------------Using Swap
void insertionSort(int *a,int n){
    int i,j,key;
    for(i=1;i<n;i++){
       j=i-1;
       key=a[i];
       while(j>=0&&a[j]>key){
        swap(a[j+1],a[j]);
        j--;
       }
    }
}
//---------------------------------------Without Swapping (True insertion Sort)

void insertionSort2(int *a,int n){
    int i,j,key;
    for(i=1;i<n;i++){
       j=i-1;
       key=a[i];
       while(j>=0&&a[j]>key){
        a[j+1]=a[j];
        j--;
       }
     a[j+1]=key;
    }

}
//--------------------------------------------Print Function
void print(int *a,int n){
    for(int i=0;i<5;i++)
        cout<<a[i]<<" "<<endl;

}

int main(){

int a[]={5,1,2,0,6};
insertionSort2(a,5);
print(a,5);
return 0;
}
