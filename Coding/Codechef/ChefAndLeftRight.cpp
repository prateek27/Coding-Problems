#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long
#define MOD 1000000007LL

char s[100005];

int main(){
int t;
scanf("%d",&t);

while(t--){

scanf("%s",&s);
ll nextNumber = 1 ;

for(int i=0;i<strlen(s);i++){
    if(i%2){
        if(s[i]=='l')
            nextNumber = nextNumber*2 - 1;
        else
            nextNumber = nextNumber*2 + 1;

    nextNumber = (nextNumber%MOD + MOD)%MOD;
    }
    else{
        if(s[i]=='l')
            nextNumber = nextNumber*2;
        else
            nextNumber = nextNumber*2 + 2;
        nextNumber%=MOD;
    }


}

printf("%lld\n",nextNumber);
}
return 0;
}
