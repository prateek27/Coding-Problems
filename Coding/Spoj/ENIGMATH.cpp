#include<iostream>
using namespace std;

int hcf(int a,int b){

if(b==0)
    return a;
if(a%b==0)
      return b;
      else
        return hcf(b,a%b);

}


int main(){
int t,a,b,x,y;
cin>>t;
while(t--){
        cin>>a>>b;
        x=a/hcf(a,b);
        y=b/hcf(a,b);
        cout<<y<<" "<<x<<endl;
}





return 0;
}
