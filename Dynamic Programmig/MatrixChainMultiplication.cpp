#include<iostream>
using namespace std;

int matrixMul(int *arr,int n){
int i,j,k,len;

int m[n+1][n+1];

for(i=0;i<len;i++)
    m[i][i]=0;


for(len=2;len<n;len++){
    for(i=1;i<=n-(len-1);i++){
          j = i + (len-1);
          m[i][j]=INT_MAX;
        for(k=i;k<j=j-1;k++){
            m[i][j]= min(m[i][k]+m[k+1][j]+ p[i-1]*p[k]*p[j]);

            }

        }

    }
}

int main(){
int arr[] ={1,2,3,4,3};
int n = sizeof(arr)/sizeof(int);

cout<<"No of ways :"<<matrixMul(arr,n);

return 0;
}
