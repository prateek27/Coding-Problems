#include<iostream>
using namespace std;

long long fact(int n){
long long ft=1;

for(i=2;i<=n;i++){
ft=ft*n;
    }
return ft;
}


int main(){
int n,w,t,r;
long long ans;
cin>>t>>w>>t>>r;
ans=fact(n)/(fact(w)*fact(t)*fact(r));
cout<<ans<<endl;
return 0;
}
