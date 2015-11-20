#include<iostream>
using namespace std;

int pow(int a,int b)
{
    int ans=1;
    while(b&1)
    {  ans=ans*a;
       b=b>>1;
       a=a*a;
    }

    return ans;
}

int main(){

cout<<pow(2,10);
return 0;

}
