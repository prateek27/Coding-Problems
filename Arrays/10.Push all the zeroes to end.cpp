#include<iostream>
using namespace std;


void pushZeroes(int *a,int n){
    int i,count=0;
    for(i=0;i<n;i++){
        if(a[i]!=0){
        a[count++]=a[i];
        }
    }

    for(i=count;i<n;i++){
        a[i]=0;
    }
return;
}
void pushZeroes2(int *a,int n){
int i,j;
for(i=0,j=0;i<n;i++){

    if(a[i]!=0){
        a[j++]=a[i];
    }
}
while(j<n){
    a[j++]=0;
    }
}
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int a[]={2,0,0,1,2,3,0,5,4,0,6,7};
int n = sizeof(a)/sizeof(int);
pushZeroes2(a,n);
print(a,n);
return 0;
}
