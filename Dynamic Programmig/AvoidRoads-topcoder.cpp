#include<bits/stdc++.h>
using namespace std;
/*
void parseString(char *bad,int marked[100][100]){

    char* part = strtok(bad,'{,", , }');
    while(part){
        part = strtok(NULL,'{,", , }');
        cout<<part<<endl;

    }

return ;
}
*/

int main(){
int r,c;
int bad;

cin>>r>>c>>bad;

int marked[100][100]={0};

int dp[100][100]={0};

//parseString(bad,marked);

//Scan the blocked positions
for(int i=0;i<bad;i++){
    int x,y;
    cin>>x>>y;
    marked[x][y] = 1;
}

//Preprocess first column
dp[0][0] = 1;
for(int i=1;i<r;i++){
    if(marked[i][0]==1){
        dp[i][0] = 0;
    }
    else{
        dp[i][0] = dp[i-1][0];
    }
}

//Preprocess frist row.
for(int i=1;i<c;i++){
    if(marked[0][i]==1){
        dp[0][i] = 0;
    }
    else{
        dp[0][i] = dp[0][i-1];
    }
}
//Preprocess Rest.
for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){

        dp[i][j] = marked[i][j]==0?dp[i][j]+dp[i-1][j]:0;
        dp[i][j] = marked[i][j]==0?dp[i][j]+dp[i][j-1]:dp[i][j];
    }
}

cout<<dp[r][c]<<endl;
return 0;
}
