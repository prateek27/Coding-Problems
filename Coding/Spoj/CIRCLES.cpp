#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

int main(){
    int t;
   long long  ra,rb,rc;
     double ans1;

    cin>>t;
    while(t--){
    cin>>ra>>rb>>rc;
    cout<<ra*rb*rc;
    ans1 = ra*rb*rc/( ra*rb + rb*rc + rc*ra + 2*sqrt(ra*rb*rc*(ra+rb+rc)));

    printf("%0.6lf\n",ans1);
     //cout<<ans1;
    }
return 0;
}

