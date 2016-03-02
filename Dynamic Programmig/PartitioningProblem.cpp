#include<iostream>
using namespace std;

bool partition(int *a,int n,int sum){

if(sum==0){
    return 0;
}




}

int main(){
int arr[] = {1, 5, 11, 5};
int n = sizeof(arr)/sizeof(int);

int sum=0;
for(int i=0;i<n;i++){
    sum += arr[i];
}

cout<<sum/2;

return 0;
}
