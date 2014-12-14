#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
// Given an array of m+n elements , second array has n elements.
// THIS CODE IS BUGGY

void print(int *a){
for(int i=0;i<10;i++)
cout<<a[i]<<" ";
}

void mergeArrays(int *a,int *b){
int la = 10;
int lb = 5;
int start = lb;
int i,j,n=la;
for(i=0,j=start;j<la;i++,j++){
a[j] = a[i];
}

int k=0;
i=0;j=lb;
while(k<n){
if(b[i]<a[j])
    a[k++]=b[i++];
else
    a[k++]=a[j++];
    }

}


int main(){
int a[10] = {-5.-4,-3,-2,-1};//{2,3,5,8,9};
int b[5] = { 1,4,6,10,11};

mergeArrays(a,b);
print(a);
return 0;
}

