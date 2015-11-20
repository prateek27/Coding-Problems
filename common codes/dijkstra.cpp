#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef vector<int> vi ;
typedef pair<int,int>  pp;
typedef vector<pp>  vpp ;
typedef vector<ll> VI ;
typedef pair<ll,ll>  PP;
typedef vector<PP>  VPP ;
#define si(a) scanf("%d",&a)
#define pi(a) printf("%d\n", a)
#define sl(a) scanf("%I64d",&a)
#define pl(a) printf("%I64d\n", a)
#define f(i,n) for(i=0;i<n;i++)
#define fr(i,n) for(i=n-1;i>=0;i--)
#define f1(i,n) for(i=1;i<=n;i++)
struct st{
	int x;
	int y;
};
bool fun(const st &a,const st &b)
{
	return a.x<b.x;
}
int main()
{
	int V;//Vertices
	int s;//source
	int INF=1000000;
	vector< vector<pp> > adj;
	vi dist(V,INF);
	dist[s]=0;
	priority_queue<pp,vector<pp>,greater<pp> > pq;
	pq.push(pp(0,s));
	while(!pq.empty())
	{
		pp front = pq.top();
		pq.pop();
		int d = front.first, u =front.second;
		if(d==dist[u])
			for(int j=0;j<(int)adj[u].size();j++)
			{
				pp v = adj[u][j];
				if(dist[u] + v.second < dist[v.first])
				{
					dist[v.first] = dist[u] + v.second;
					pq.push(pp(dist[v.first],v.first));
				}
			}
	}
	return 0;
}
	
	
	
	
