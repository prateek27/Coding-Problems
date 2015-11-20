#include<bits/stdc++.h>
using namespace std;

int lps(char *str)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems


   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++)
      L[i][i] = 1;

    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution (See
    // http://www.geeksforgeeks.org/archives/15553). cl is length of
    // substring
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}
int longestPalindromicSequenceDP(char *seq,int n){

int dp[100][100];

for(int i=0;i<n;i++){
    dp[i][i]=1;
}


for(int len=2;len<=n;len++){
    for(int i=0;i<n-len+1;i++){
        int j = i+len-1;


        if(j==i+1&&seq[i]==seq[j]){
                dp[i][j]=2;
        }
        else if(seq[i]==seq[j]){
            dp[i][j] = dp[i+1][j-1]+2;
        }
        else{
            dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }
  }

return dp[0][n-1];
}

int longestPalindromicSequenceRecursive(char*seq,int i,int j){

    if(i==j){
        return 1;
    }

    if(j==i+1 && seq[i]==seq[j]){
        return 2;
    }

    if(i<j&&seq[i]==seq[j]){
        return 2+longestPalindromicSequenceRecursive(seq,i+1,j-1);
    }
    else{
        return max(longestPalindromicSequenceRecursive(seq,i+1,j),longestPalindromicSequenceRecursive(seq,i,j-1));
    }

}

int main(){

 char seq[] = "GEEKSFORGEEKS";
 int n = strlen(seq);
 cout<<longestPalindromicSequenceRecursive(seq,0,n-1)<<endl;
cout<<longestPalindromicSequenceDP(seq,n)<<endl;
cout<<lps(seq)<<endl;
return 0;
}
