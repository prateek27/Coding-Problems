#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int a[10][100001];
char str[100001];

int main(){
int n,m,i,j;
char ch;
for(int i=0;i<10;i++)
    for(j=0;j<100001;j++)
            a[i][j]=0;

scanf("%d%d%c",&n,&m,&ch);

for(i=0;i<n;i++)
    scanf("%c",&str[i]);

cout<<str;
for(i=0;i<n;i++)
{
    int digit = str[i]-'0';
    a[digit][i]++;

}

for(int j=1;j<n;j++)
{
    for(i=0;i<10;i++)
        a[i][j]+=a[i][j-1];
}

int index;

while(m--){
    int ans=0;
    scanf("%d",&index);
    index--;
    int actual=str[index]-'0';

    for(int k=0;k<10;k++)
    {
    int temp=str[k]-'0';
     int psum= (a[k][index]*(actual-k));
     if(psum>=0)
        ans+=psum;
     else
        ans+=-1*psum;

    }

    printf("%d\n",ans);
}

return 0;
}
