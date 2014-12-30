#include<iostream>
#include<algorithm>
using namespace std;

int findMaxProduct(int *a,int n){

int product =1;
int countp =0 , countn=0;
int i,Min = -10000;
for(i=0;i<n;i++){
    if(a[i]>0)
     countp++;
    else if(a[i]<0){
       countn++;
    }
}
sort(a,a+n);
/*Cases:
All positive - Greedy
2 positive , 1 negative - Greedy
1 positive , 2 negative - Choose the last two of min
3 negative - Greedy
*/
if(countp==1){
    product = a[0]*a[1]*a[n-1];
}
else{
  product = a[n-1]*a[n-1]*a[n-3];
}
return product;
}




int main(){

int a[] = { -8,1,2,-2,-3,3,4,};
cout<<findMaxProduct(a,sizeof(a)/sizeof(int));
}
