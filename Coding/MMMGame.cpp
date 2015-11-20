#include<iostream>
#include<cstdio>
using namespace std;

int main(){
int t;
scanf("%d",&t);

while(t--)
{   int n;
    scanf("%d",&n);

    int ans=0;
    int num;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        if(num>=i)
            ans=ans^num;
    }
if(ans)
    printf("ALICE\n");
else
    printf("BOB\n");
}
return 0;
}
