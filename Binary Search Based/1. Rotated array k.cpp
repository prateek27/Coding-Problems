#include<iostream>
using namespace std;
// Problem:A sorted array has been rotated by some number k in clockwise direction.Find K.


int findRotatedPoint(int *a,int low,int high){

while(low<=high){ //Converge to a single element
    int mid = low + (high-low)/2;

    if(low==high)
        return low;

    if(a[mid]<a[high]){  //lies in the second half
        //Shrink from right
        high=mid;
    }
    else{
    //Lies in the first half - Shrink from left
        low=mid+1; //Note it should be mid+1 , mid gives infinite loop
    }
}
return -1;
}
int main(){
int a[]={5,6,1,2,3,4};
int n = sizeof(a)/sizeof(a[0]);
cout<<findRotatedPoint(a,0,n-1);
return 0;
}
