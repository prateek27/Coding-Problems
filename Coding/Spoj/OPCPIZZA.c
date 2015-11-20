#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t;long long n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1)
            cout<<((n-1)*(n-1)/4)%n<<endl;
        else
            cout<<((n-2)*(n-2)/4)%n<<endl;


    }

return 0;
}
