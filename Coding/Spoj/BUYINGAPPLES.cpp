#include<iostream>
#include<cstdio>
#define readint(n)  scanf("%d",&n)
using namespace std;


int wt[1001];
int val[1001];
int a[1001];
int max(int a,int b){

return (a>b?a:b);
}

int knapSack(int W,int N,int packets)
{
    int K[N+1][W+1];
    int i,w;
   int count=0;
  for (i = 0; i <= N; i++)
   {

       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0000;
           else if (wt[i-1] <= w)
                {
                    if(val[i-1] + K[i-1][w-wt[i-1]]<K[i-1][w])
                    count++;

                 K[i][w] = min(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);

                }
           else
                 K[i][w] = K[i-1][w];
                 cout<<K[i][w]<<" ";

       }
    cout<<endl;
   }
   cout<<"count"<<count;
return -1*K[N][W];
}



int main(){
int t,W,N,i;
readint(t);
while(t--){
    readint(W);
    readint(N);
    for(i=0;i<N;i++)
        readint(a[i]);
    int j=0;
    for(i=0;i<N;i++){
        if(a[i]!=-1)
        {
            val[j]=-a[i];
            wt[j]=i+1;
            j++;
        }
    }
    int packets=W;
    cout<<knapSack(N,j,packets)<<endl;

}


return 0;
}

