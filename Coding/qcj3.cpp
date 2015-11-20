#include<iostream>
#include<cstdio>
using namespace std;

int main(){
int t;
scanf("%d",&t);

while(t--)
{ int n;
    scanf("%d",&n);

    int ans=0;int num;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        int temp=num;
        while(temp--)
        {
            ans=ans^i;
        }
    }
if(ans)
    printf("Tom Wins\n");
else
    printf("Hanks Wins\n");
}
return 0;
}
