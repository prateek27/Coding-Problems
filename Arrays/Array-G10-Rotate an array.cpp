#include<iostream>
using namespace std;


void rotate(int *a,int n,int d){
int i;
int *temp = new int[d];
for(i=0;i<d;i++){
    temp[i]=a[i];
}
i=0;
int k=0;
for(int j=0;j<n;j++)
{
    if(i<d-1){
        a[i++]=a[j+d];
    }
    else{
        a[i++]=temp[k++];
        }
    }
}

void print(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i];

}

int main(){
int a[]={1,2,3,4,5};
int n=sizeof(a)/sizeof(int);
rotate(a,n,3);
print(a,n);
return 0;
}
