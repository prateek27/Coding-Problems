#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;

int i,j;
int count=0;
for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
        if(i*j<=n)
            count++;
    }
}
cout<<count<<endl;

return 0;
}
