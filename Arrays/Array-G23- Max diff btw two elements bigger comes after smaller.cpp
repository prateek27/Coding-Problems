#include<iostream>#include<iostream>
#include<queue>
#include<functional>
using namespace std;

/* Find max difference between two elements */
int find_max_difference(int *a,int n){
int min_till_now = 10000;
int diff_till_now =0;

for(int i=0;i<n;i++){
    int diff = a[i]-min_till_now;

    diff_till_now = max(diff,diff_till_now);
    min_till_now = min(min_till_now,a[i]);
}


return diff_till_now;
}

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8 };
    int i, n = sizeof(arr)/sizeof(arr[0]);
    cout<<find_max_difference(arr,n);

    return 0;
}

