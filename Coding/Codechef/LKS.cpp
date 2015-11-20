#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 2000005
//int K[MAX][W+1];
int max(int a, int b) { return (a > b)? a : b; }

int a[MAX],b[MAX];
int myKnapsack(int W,int wt[],int val[],int N)
{ int i,j;
    for(i=0;i<=W;i++)
        a[i]=0;

    b[0]=0;
     j=0;
   for(j=0;j<N;j++){
    for(i=0;i<=W;i++)
    {
        if(wt[j]<=i)
        b[i]=max(val[j]+a[i-wt[j]],a[i]);
        else
            b[i]=a[i];

    }
    for(int k=0;k<=W;k++)
        a[k]=b[k];
}
return b[W];
}
/*
int knapSack(int W,int wt[],int val[],int N){

int i,w;
for(i=0;i<=N;i++)
{
  for(w=0;w<=W;w++)
  {
      if(i==0||w==0)
        K[i][w]=0;
      else
        K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
      else
        K[i][w]=K[i-1][w];


  }

}

return K[N][W];
}
*/
int val[501];
int wt[501];
int main(){
  int i=0,K,N,t;
scanf("%d%d",&K,&N);
t=N;
while(N--)
{
    scanf("%d%d",&val[i],&wt[i]);
    i++;
}
printf("%d",myKnapsack(K,wt,val,t));

return 0;
}


