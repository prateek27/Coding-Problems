#include<iostream>
using namespace std;

//---------------------------------------Using Swap
void selectionSort(int *a,int n){
    int i,j,key;
    for(i=0;i<n-1;i++){
      int min_index = i;

        for(j=i+1;j<n;j++){
            if(a[j]<a[min_index])
                min_index=j;
        }
      swap(a[i],a[min_index]);
    }
}
//--------------------------------------------Print Function
void print(int *a,int n){
    for(int i=0;i<5;i++)
        cout<<a[i]<<" "<<endl;

}

int main(){

int a[]={5,1,2,0,6};
selectionSort(a,5);
print(a,5);
return 0;
}
