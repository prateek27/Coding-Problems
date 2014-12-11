#include<iostream>
using namespace std;
//Problem : Given a Sorted Array . Find the pair and triplet that sums to zero.
//-10 -9 -8 7 9 11 12

//Time Complexity Pair O(n) , Triplet O(n*n)

void getMeAZeroSumPair(int *a,int n){
int i,j;
for(i=0,j=n-1;i<j;){
    if(a[i]+a[j]==0){
    cout<<"Zero Sum Found :"<<a[i]<<"+"<<a[j]<<endl;
    i++ ; j--;
    }
    else if(a[i]+a[j]<0){
     i++;
    }
    else{
        j--;
        }
    }
}

void getMeAZeroSumTriplet(int *a,int n){
// This can be done O(n^2) Fix one element and use previous algo for each

int i,j,current,k;

for(i=0;i<n;i++){
    int current=a[i];
for(k=0,j=n-1;k<j;){

    if(k==i){
     k++; continue;
    }

    if(j==i){
    j--;continue;
    }

    if(a[k]+a[j]== -current){
    cout<<"Triplet Found "<<a[i]<<","<<a[j]<<" ,"<<a[k]<<endl;
    k++;j--;
    }
    else if(a[k]+a[j]< -current){
    k++;
    }
    else{
    j--;
    }
}

}


}


int main(){

int a[]={-10 ,-9 ,-8, 7, 9, 11, 12};
int b[]={-10 ,-9 ,-8, 4, 5, 11, 12};

int n= sizeof(a)/sizeof(int);
getMeAZeroSumPair(a,n);
getMeAZeroSumTriplet(b,n);
return 0;
}
