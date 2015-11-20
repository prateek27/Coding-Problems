#include<iostream>
using namespace std;


int count[1000005];

int main(){


int t;
scanf("%d",&t);
while(t--)
    {
    int a,b,c,d,n;
    int temp = n ;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    int af = d;

    while(n--){
    int an = (a*af*af + b*af + c)%1000000;
    count[an]++;
    af=an;
    }
    for(n=)

    }
return 0;
}
