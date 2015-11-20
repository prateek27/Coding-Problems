#include<iostream>
#include<cstdio>
using namespace std;

int toBinary(int n){
unsigned i;
for(i=1<<31;i>0;i>>=1)
  (n&i)?printf("1"):printf("0");

}


int main(){
int x=1;
while(x){
    cin>>x;
    toBinary(x);
}

return 0;
}
