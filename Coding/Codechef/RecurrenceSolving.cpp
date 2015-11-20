#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MAX 110
#define si(n) scanf("%llu",&n);
#define sl(n) scanf("%llu",&n);
#define MOD 1000000007
#define printl(n) ("%llu\n",n);
#define int long long unsigned


int T[15][15];
int jumps[16];
int result[15][15];
int temp[15][15];

//Function for matrix Multiplication
void multiplyMod(int M1[15][15],int M2[15][15],int mod){


    int i,j,k;
    FOR(i,0,15){
        FOR(j,0,15){
            temp[i][j]=0;
            FOR(k,0,15){
                temp[i][j]+= M1[i][k]*M2[k][j];
                temp[i][j]%=mod;
            }
        }
    }
    FOR(i,0,15){
        FOR(j,0,15){
            M1[i][j]=temp[i][j];
        }
    }
}


//Function for matrix exponentiation
int power(int base[15][15],int n,int mod){

CLEAR(result);
FOR(i,0,15)
    result[i][i]=1;

while(n){

    if(n&1)
        multiplyMod(result,base,mod);

    multiplyMod(base,base,mod);
    n>>=1;
    }
return result[14][14];
}
void initialise(){
    int i,j;
    //Initialsize some i+1 element in ith row as 1
    FOR(i,0,14){
        T[i][i+1]=1;
    }
    //Initalise Last Row
    FOR(i,0,15){
        T[14][i] = jumps[15-i];
    }
}






main(){
    int tc,i,j;
    si(tc);
    while(tc--){
        int N,K;
        si(N);
        si(K);

    CLEAR(T);
    CLEAR(jumps);
    CLEAR(result);
    CLEAR(temp);

        FOR(i,0,K)
        {
            int l;
            si(l);
            jumps[l]=1;
        }
        initialise();
        int a= power(T,N,MOD);
        printf("%lld\n",a);
    }

return 0;
}
