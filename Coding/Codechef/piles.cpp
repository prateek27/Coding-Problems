#include<iostream>
using namespace std;

int main(){
long long int t,p,q;
cin>>t;
while(t--){
    cin>>p>>q;
    if((p%2+q%2)%2==0){
        cout<<"B"<<endl;
    }
    else{
        cout<<"A"<<endl;
    }


}
return 0;
}
