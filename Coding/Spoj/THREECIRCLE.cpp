#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

int main(){
    int t;
    double ra,rb,rc;
    double  ans1;

    cin>>t;
    while(t--){
    cin>>ra>>rb>>rc;

    ans1 = (1/( 1/ra + 1/rb+  1/rc + 2*sqrt((ra+rb+rc)*((1/ra)*(1/rb)*(1/rc)))));
   // cout<<ans1;
    printf("%0.6lf\n",ans1);



    }
return 0;
}

