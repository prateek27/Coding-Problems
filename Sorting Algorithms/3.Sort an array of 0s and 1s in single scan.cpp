#include<iostream>
using namespace std;

//-------------------------------------Method 1 : Count Method Push 1's to end.
void sort0s1s(int *a,int n){
    int i,count=0;
    for(i=0;i<n;i++){
        if(a[i]!=0){
        a[count++]=0;
        }
    }
    //Note the difference
    for(i=n-count;i<n;i++){
        a[i]=1;
    }
return;
}
//-----------------------------------Method 2 In One Pass (note the order of if if else if) Like DNF algorithm
void sortInOnePass(int *a,int n){
int low=0;
int high=n-1;
while(low<high){
    if(a[low]==0)
        low++;

    if(a[high]==1)
        high--;
   else if(a[low]>a[high] ){
        swap(a[low],a[high]);
        low++;high--;
    }
  }
}
//------------------------------------Print
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int a[]=  {1,1,0,1,0,0,0,1,1,1,0,0}; //{0, 1, 0, 1, 1, 1};
int n = sizeof(a)/sizeof(int);
//sort0s1s(a,n);
sortInOnePass(a,n);
print(a,n);
return 0;
}
