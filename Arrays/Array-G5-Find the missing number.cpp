#include<iostream>
using namespace std;

//Given n-1 integers of range 1-n. Find the missing number
int findMissingUsingSumFormula(int*a,int n){

int sum = ((n)*(n+1))/2;
int current_sum =0;
for(int i=0;i<n-1;i++){
    current_sum += a[i];
}
return sum - current_sum;
}

int findMissingUsingXOR(int *a,int n){
    int xor1=0;
    int xor2=0;
    int i;
    for(i=1;i<=n;i++)
        xor1=xor1^i;

    for(i=0;i<n-1;i++)
        xor2=xor2^a[i];

return xor1^xor2;
}

int main(){
 int a[] =  {1,2,3,5,6,7};
   int n = sizeof(a)/sizeof(a[0]);
    cout<<"Using sum formula missing number is "<<findMissingUsingSumFormula(a,n+1)<<endl;
    cout<<"Using XOR number is "<<findMissingUsingXOR(a,n);
}
