#include<iostream>
using namespace std;

int main(){
long long t,k,n,a[100],i,count=0;
cin>>t;
while(t--){
    cin>>n;
    for(i=1;i<=n;i++){ cin>>a[i]; }
    cin>>k;
    for(i=1;i<=n;i++) { if(a[i]<a[k]) count++;    }
    cout<<count+1<<endl;
    count=0;
}
return 0;
}
