#include<iostream>
#include<queue>
#include<climits>
#include<cstdio>
using namespace std;
#define MAX 101

int arr[MAX][MAX];
int dist[MAX][MAX];
int mark[MAX][MAX];

struct node{
int x,y,time;

    node(int a,int b,int t){
    x=a;
    y=b;
    time=t;
    }
};

bool operator<(const node&a,const node &b)
{
    return a.time>b.time;
}

int main(){
int t,n,m,u,i,j,r,c;

scanf("%d",&t);
while(t--){
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&arr[i][j]); //Scan the time for each position
            dist[i][j]=INT_MAX; //All distances initially infinity
            mark[i][j]=1; //All vertices initially marked with 1
        }
    }
    scanf("%d%d%d",&n,&m,&u);

    int m1[]={-1,0,1,0};
    int m2[]={0,-1,0,1};

    priority_queue<node> q;

    node source=node(1,1,arr[1][1]);
    dist[1][1]=arr[1][1];
    q.push(source);

    while(!q.empty())
    {
    node p = q.top();
    q.pop();
    mark[p.x][p.y]=2;
    for(int k=0;k<=3;k++)
    {
            int x1 = m1[k] + p.x;
            int y1 = m2[k] + p.y;
            //Check bounds
            if(x1>=1 && x1<=r && y1>=1 && y1<=c)
            {
                if(mark[x1][y1]==1)
                {
                    mark[x1][y1]=0;
                    dist[x1][y1]=min(dist[x1][y1],arr[x1][y1]+dist[p.x][p.y]);
                    node value=node( x1,y1,arr[x1][y1]+dist[p.x][p.y] );
                    q.push(value);
                }

                else if(mark[x1][y1]==0)
                        dist[x1][y1]=min(dist[x1][y1],arr[x1][y1]+dist[p.x][p.y]);


            }

        }

    }

/*    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cout<<dist[i][j]<<" ";
        }
    cout<<endl;
    }
*/

    if(dist[n][m]<=u)
   	printf("YES\n%d\n",u-dist[n][m]);
   	else
   	printf("NO\n");
}
return 0;
}
