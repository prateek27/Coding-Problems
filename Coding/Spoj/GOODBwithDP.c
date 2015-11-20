#include<iostream>
using namespace std;

int coeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}
int main(){
int n,w,t,r;
long long ans;
cin>>n>>w>>t>>r;
ans= coeff(n,w)*coeff(n-w,t)*coeff(n-w-t,r);
cout<<ans<<endl;
return 0;
}
