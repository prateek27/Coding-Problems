#include<iostream>
#include<cstdio>
using namespace std ;

inline int calculateA(int a[],int n , int ans){
for(int i=0;i<n;i++){
    ans=ans&a[i];

}
return ans;
}

inline int calculateO(int a[],int n , int ans){
for(int i=0;i<n;i++){
    ans=ans|a[i];
    }
    return ans;
}

inline int calculateX(int a[],int n , int ans , int k)
{
if(k==0){ return ans; }

else if(k%2==0){
    for(int i=0;i<n;i++){ ans=ans^a[i]; }
    return ans;
        }
else
    return 0;
}

int main(){
long long int t,n,k,ians,i;
char oper[4];

cin>>t;
while(t){
cin>>n>>k>>ians;
int a[n];
     for(i=0;i<n;i++){
     cin>>a[i];
     }
     cin>>oper;

switch(oper[0]){
case 'A': cout<<calculateA(a,n,ians)<<endl;break;
case 'O': cout<<calculateO(a,n,ians)<<endl;break;
case 'X': cout<<calculateX(a,n,ians,k)<<endl;break;

t--;
}



}
return 0;
}
