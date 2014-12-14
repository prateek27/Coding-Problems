#include<iostream>
using namespace std;

//---------------------------------------Using Swap
void bubbleSort(int *a,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }

    }
}
//--------------------------------------------Print Function
void print(int *a,int n){
    for(int i=0;i<5;i++)
        cout<<a[i]<<" "<<endl;

}

int main(){

int a[]={5,1,2,0,6};
bubbleSort(a,5);
print(a,5);
return 0;
}
