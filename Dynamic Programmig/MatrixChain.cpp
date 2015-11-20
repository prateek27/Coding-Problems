#include<iostream>
#include<climits>
using namespace std;


// Matrix p[i] has dimension p[i]*p[i-1] for i = 1...n
int MatrixChainDP(int *p,int n){
int mat[100][100];

for(int i=1;i<n;i++){
    mat[i][i] = 0;
}

for(int len=2;len<=n-1;len++){
    for(int start=1;start<=n-len+1;start++){
        int end = start + len -1;

        mat[start][end] = INT_MAX;
        for(int k = start;k<end;k++){

            mat[start][end] = min(mat[start][end], mat[start][k]+mat[k+1][end]+ p[start-1]*p[k]*p[end]);

        }

    }

}


return mat[1][n-1];
}



int MatrixChain(int *p,int i,int j){

if(i>=j){
    return 0;
}


int cnt ;
int mini = INT_MAX;
    for(int k=i;k<j;k++){
        cnt =  MatrixChain(p,i,k)+MatrixChain(p,k+1,j)+ p[i-1]*p[k]*p[j] ;
    }

mini = min(mini,cnt);
return mini;
}


int main(){
int arr[] = {1, 2, 3, 4};
//Note the calling parameters.
cout<<MatrixChain(arr,1,3)<<endl;
cout<<MatrixChainDP(arr,4)<<endl;

return 0;
}
