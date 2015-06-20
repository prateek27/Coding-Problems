#include<iostream>
#include<algorithm>
using namespace std;


int closestToZeroSum(int *a,int n){
    sort(a,a+n);
    int l=0,r=n-1;

    int closest_sum = 100000;
    while(l<r){
        int temp = a[l]+a[r];
        closest_sum=min(abs(closest_sum),abs(temp));
        if(temp>0){
            r--;
        }
        else{
            l++;
        }

    }
return closest_sum;
}

int main(){
int a[]={1, 60, -10, 70, -80, 85};
int n=sizeof(a)/sizeof(int);
cout<<closestToZeroSum(a,n);
return 0;
}
