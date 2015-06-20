#include<iostream>
using namespace std;



int kadanes(int *a,int n){
int sum_here = 0;
int max_here =0;

for(int i=1;i<n;i++){
    sum_here= sum_here + a[i];
    if(sum_here<0)
        sum_here=0;
    max_here = max(max_here,sum_here);

}

return max_here;
}



int main(){
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = kadanes(a, n);
   cout<<max_sum<<endl;

return 0;
}
