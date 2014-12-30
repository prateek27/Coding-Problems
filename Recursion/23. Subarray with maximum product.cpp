#include<iostream>
using namespace std;

int findMaxProduct(int *a,int n){

int product =1,negativeProduct=1;
int i,Min = -10000;
for(i=0;i<n;i++){
    if(a[i]>0)
     product*=a[i];
    else if(a[i]<0){
        negativeProduct *= a[i];
        Min = max(Min,a[i]);
    }

}
if(negativeProduct<0){
    negativeProduct /= Min;
}
return product*negativeProduct;
}




int main(){

int a[] = { -8,1,2,-2,-3,3,4,};
cout<<findMaxProduct(a,sizeof(a)/sizeof(int));

}
