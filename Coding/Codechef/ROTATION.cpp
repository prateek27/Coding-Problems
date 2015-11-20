#include<iostream>
#include<cstdio>
#include<cstring>
#include<list>
using namespace std;
#define ll long long
#define MOD 1000000007

int arr[100005];

int main(){
int t,val;
int n,m,i;

scanf("%d%d",&n,&m);

for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }

ll ans=0;
while(m--){

    char ch;int d;
    cin>>ch>>d;


      if(ch=='C')
      {
       ans = (ans+d)%n;
      }
      else if(ch=='A')
        {

         ans += (n-d)%n;
        }
     else{
        printf("%d\n",arr[(d-1+ans+n)%n]);
     }
}
return 0;
}
