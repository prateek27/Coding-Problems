#include<iostream>
#include<cstdio>
using namespace std;
typedef long long bignum;
struct pair{
    bignum x,y;
    pair(bignum a, bignum b){
        x=a, y=b;
    }
};

bignum mulmod(bignum a,bignum b,bignum c){
    bignum x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b >>= 1;
        //prbignumf("%llu))\n", b);
    }
    return x%c;
}


bignum pow(bignum base, bignum exponent, bignum modulo)
{//implement for the case when base is an nxn matrix. Targeted running time: O(n^3 log(exponent)).
    bignum ans=1;
    while(exponent>0)
    {
        //printf("%llu)\n", exponent);
        if(exponent%2==1)
            ans=mulmod(ans, base, modulo);
        exponent>>=1;
        base=mulmod(base, base, modulo);
    }
    return ans;
}

bignum modInverse(bignum a, bignum m) {
    return pow(a,m-2,m);
}

bignum binomial(bignum n, bignum k, bignum m){
    if(k> n/2)
        return binomial(n, n-k, m);
    bignum num=1, nterm=n;
    for(bignum i=0; i<k; i++){
        num=mulmod(num, nterm, m);
        nterm--;
    }
    bignum den=1;
    for(bignum i=2; i<=k; i++){
        den=mulmod(den, i, m);
    }
    return mulmod(num, modInverse(den, m), m);
}

int main(){
    bignum t;
    scanf("%lli", &t);
    for(bignum i=0; i<t; i++){
        bignum n, k;
        scanf("%lli %lli", &n, &k);
        bignum b=binomial(n, k-1, 1000000007);
        bignum b2=mulmod(b, b, 1000000007);
        bignum num=mulmod(b2, n-k+1, 1000000007);
        bignum den=mulmod(n, k, 1000000007);
        printf("%lli\n", mulmod(num, modInverse(den, 1000000007), 1000000007));
    }
}
