#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t;
    long long ra,rb,rc;
    float  ans1,ans2;

    cin>>t;
    while(t--){
    cin>>ra>>rb>>rc;
    ans1 = ra*rb*rc/( ra*rb + rb*rc + rc*ra + 2*sqrt(ra*rb*rc*(ra+rb+rc)));
    ans2 = ra*rb*rc/( ra*rb + rb*rc + rc*ra - 2*sqrt(ra*rb*rc*(ra+rb+rc)));

    if(ans1>=0)
    printf("%0.6f\n",ans1);

    else if(ans2>=0)
    printf("%0.6f\n",ans2);

    }

return 0;
}

