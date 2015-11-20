#include<iostream>
using namespace std;

#define MOD 1000000007
long long fact(int n){
long long ft=1;
if(n==0) return 1;
int i;
for(i=2;i<=n;i++){
ft=ft*i%MOD;
}
return ft;
}


int main(){
int n,w,t,r;
long long ans;
cin>>n>>w>>t>>r;
ans=(fact(n)/((fact(w)*fact(t)*fact(r))%MOD))%MOD;
cout<<ans<<endl;
return 0;
}
