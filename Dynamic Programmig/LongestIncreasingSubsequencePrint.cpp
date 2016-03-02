#include<iostream>
#include<cstring>
using namespace std;



int lcs(char *X,char *Y,int m,int n){

int lcs[m+1][n+1];

for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0||j==0){
            lcs[i][j]=0;
        }
        else{
         if(X[i-1]==Y[j-1]){
            lcs[i][j] = lcs[i-1][j-1]+1;
         }
         else{
            lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
         }
        }
    }

}
//Code to Print the sequence.
int i=m,j=n;
int len = lcs[m][n];
char *ans = new char[len];
ans[len] = '\0';
while(i>0 && j >0){
    if(X[i-1]==Y[j-1]){
     ans[len-1]= X[i-1];
     i--;len--;j--;
    }
    else if(lcs[i-1][j]>lcs[i][j-1]){
        i--;
        }

    else{
        j--;
    }

}
cout<<ans<<endl;

return lcs[m][n];
}


int main(){
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  cout<<lcs(X, Y, m, n);
  return 0;

return 0;
}
