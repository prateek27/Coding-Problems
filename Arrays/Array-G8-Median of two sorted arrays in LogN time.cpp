#include<iostream>
using namespace std;


//Approach 1: Merging approach O(N)
//Approach 2 : LogN method
int median(int *a,int n){
    if(n%2==0)
        return (a[n/2]+a[n/2-1])/2.0;
    else
        return (a[n/2]);
}




float findMedian(int *a,int *b,int n){
if(n==0)
    return -1;
if(n==1)
    return a[0];
if(n==2)
    return (max(a[0],b[0])+min(a[1],b[1]))/2.0;



int m1=median(a,n);
int m2 = median(b,n);

if(m1==m2)
    return m1;

if(m1<m2){
    if(n%2==0){
        return findMedian(a+n/2-1,b,n-n/2+1);
    }
    else
    {
        return findMedian(a+n/2,b,n-n/2);
    }
}
else{
    if(n%2==0){
        return findMedian(b+n/2-1,a,n-n/2+1);
    }
    else{
        return findMedian(b+n/2,a,n-n/2);
    }
}


}

int main(){
    int a[] = {1, 5,7,8};
    int b[] = {2,3,4,7};
    int n=sizeof(a)/sizeof(int);
    cout<<findMedian(a,b,n);

return 0;
}
