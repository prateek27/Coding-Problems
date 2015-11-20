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

void dfs(int v, bool visited[],list<int> *adj)
{
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            dfs(*i, visited,adj);
}
 
int main()
{
    int V;    // Vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    adj = new list<int>[V];
 
//    adj[v].push_back(w); // Add w to v’s list.
	bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            dfs(i, visited,adj);
 
    return 0;
}
