#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;

stack<char> s;
char a[1000005];

int main(){
int t,i,ans;
scanf("%d",&t);

while(t--){
scanf("%s",&a);
ans=0;
int pre=0;
int len=strlen(a);

    for(i=0;i<len;i++)
    {
        if(a[i]=='<')
      {s.push(a[i]);
        pre++;
        }

        else if(a[i]=='>')
        {
            if(!s.empty()&&s.top()=='<')
                { ans+=2;s.pop();pre--; }


        }

    }
    while(!s.empty())
        s.pop();
if(pre==0)
printf("%d\n",ans);
else
printf("0\n");
}

return 0;
}
