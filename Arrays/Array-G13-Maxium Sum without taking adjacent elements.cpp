#include<iostream>
using namespace std;


int findMaxSum(int *a,int n){
int sum_including_prev=a[0];
int sum_excluding_prev=0;
int i;
    for(i=1;i<n;i++){
        int temp=max(sum_excluding_prev,sum_including_prev);
        sum_including_prev = sum_excluding_prev+a[i];
        sum_excluding_prev = temp;
    }

return max(sum_including_prev,sum_excluding_prev);
}

int main(){
int a[]={5,  5, 10, 40, 50, 35};
int n=sizeof(a)/sizeof(int);
cout<<findMaxSum(a,n);

return 0;
}
