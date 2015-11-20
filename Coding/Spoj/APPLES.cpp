#include<iostream>
#include<cstdio>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W,int wt[],int val[],int N){
int K[N+1][W+1];
int i,w;
for(i=0;i<=N;i++)
{
  for(w=0;w<=W;w++)
  {
      if(i==0||w==0)
        K[i][w]=0;
      else if(wt[i-1]<=w)
        K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
      else
        K[i][w]=K[i-1][w];


  }

}

return K[N][W];
}

int val[2001];
int wt[2001];
int main(){
  int i=0,K,N,t;

t=N;
while(N--)
{   cin>>K>>N;
    scanf("%d%d",&wt[i],&val[i]);
    i++;
}
cout<<knapSack(K,wt,val,t);

return 0;
}
