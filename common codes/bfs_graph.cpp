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
    int V;    // Vertices
    int s;
    list<int> *adj;    // Pointer to an array containing adjacency lists
    adj = new list<int>[V];
 
//    adj[v].push_back(w); // Add w to v’s list.
	bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    } 
 
    return 0;
}
