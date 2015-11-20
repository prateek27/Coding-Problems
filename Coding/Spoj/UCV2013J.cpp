#include<iostream>
using namespace std;

int main(){
long sum=0,n,i;

while(1){
    cin>>n;
    if(n==0){ break;}
    else {
        int a[n];
        for(i=0;i<n;i++){ cin>>a[i];}
        for(i=n/2;i<n;i++){ sum=sum+a[i]; }
        cout<<sum<<endl;


    }

sum=0;
}


return 0;
}
