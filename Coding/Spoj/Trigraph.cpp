#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 100000000
using namespace std;

int minu(int a,int b,int c ,int d){
int m;
m =a>b?b:a;
m= m>c?c:m;
m= m>d?d:m;
return m;
}
int minu(int a,int b,int c ){
int m;
m =a>b?b:a;
m= m>c?c:m;

return m;
}
int minu(int a,int b ){
int m;
m =a>b?b:a;

return m;
}





int main(){
int n;int num=1;
while(scanf("%d",&n),n!=0)
{

int a[n][3],cost[n][3];
int i,j;
for(i=0;i<n;i++)
        for(j=0;j<3;j++)
            cin>>a[i][j];

cost[0][0]=INF;
cost[0][1]=a[0][1];
cost[0][2]=a[0][1]+a[0][2];


for(i=1;i<n;i++){
    for(j=0;j<3;j++){
       if(j==0)
        cost[i][j]=minu(cost[i-1][j],cost[i-1][j+1])+a[i][j];

       if(j==1)
        cost[i][j]=minu(cost[i-1][j-1],cost[i-1][j],cost[i-1][j+1],cost[i][j-1])+a[i][j];

        else
        cost[i][j]=minu(cost[i][j-1],cost[i-1][j],cost[i-1][j-1])+a[i][j];
    }
}
printf("%d. %d\n",num++,cost[n-1][1]);

}


return 0;
}


