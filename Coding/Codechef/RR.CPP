#include<iostream>
#include<cstdio>
using namespace std ;



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

if(oper[0]=='A')
{   for(int i=0;i<n;i++){
    ians=ians&a[i]; }
    cout<<ians<<endl;
    continue;
}
else if(oper[0]=='O'){
    for(int i=0;i<n;i++){
    ians=ians|a[i];

} cout<<ians<<endl; continue;
}

else if(oper[0]=='X'){
if(k==0){ cout<<ians;continue; }

else if(k%2==0){
    for(i=0;i<n;i++){ ians=ians^a[i]; }
     cout<<ians<<endl;
}
}
t--;
}




return 0;
}






