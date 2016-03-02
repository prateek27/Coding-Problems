#include<iostream>
#include<cstring>
using namespace std;


int longestPalindromicSubstringDP(char *str,int n){

bool dp[n][n];

int maxLen =1;
int maxIndex =0;

for(int i=0;i<n;i++){
    //1 length substrings are all palindromes.
    dp[i][i] = true;
}

for(int i=0;i<n-1;i++){
    //2 length substrings.
    if(str[i]==str[i+1]){
        dp[i][i+1] = true;
        maxLen =2;
        maxIndex = i;
    }
}


for(int k=3;k<=n;k++){
    for(int i=0;i<n-k+1;i++){
        int j = i + k -1;

        if(dp[i+1][j-1]&& str[i]==str[j]){
            dp[i][j]=true;
            if(k>maxLen){
                maxLen = k;
                maxIndex = i;
            }

        }
        else{
            dp[i][j] = false;
        }


    }

}


return maxLen;
}


int main(){
    char str[] = "forgeeksskeegfor";
    cout<<longestPalindromicSubstringDP(str,strlen(str));

}
