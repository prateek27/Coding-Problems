#include<iostream>
using namespace std;


int main(){
int n,t,i;
long long unsigned moves[40];
cin>>t;
while(t--){
cin>>n;
moves[1]=2;
for(i=2;i<=40;i++)
   moves[i]=3*moves[i-1]+2;
  cout<<moves[n]<<endl;
}

return 0;
}

