#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>

using namespace std;
typedef long long ll ;
typedef vector<int> vi ;
typedef pair<int,int>  pp;
typedef vector<pp>  vpp ;
typedef vector<ll> VI ;
typedef pair<ll,ll>  PP;
typedef vector<PP>  VPP ;
#define pb push_back
#define mp make_pair
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
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
//inside main()
vi pset;//pset means parent set
void initset(int N)
{
	pset.assign(N,0);
	for(int i=0;i<N;i++)
		pset[i]=i;
}
int findset(int i)
{
	return (pset[i]==i)?i:(pset[i]=findset(pset[i]));
}
bool issameset(int i,int j)
{
	return findset(i)==findset(j);
}
void unionset(int i,int j)
{
	pset[findset(i)]=findset(j);
}
vector<pair<int,pp> > edgelist;//weight,two vertices of edge
int main()
{
	int E,a,b,weight,V;
	cin>>E;
	cin>>V;
	for(int i=0;i<E;i++)
	{
		scanf("%d %d %d",&a,&b,&weight);
		edgelist.push_back(make_pair(weight,pp(a,b)));
	}
	sort(edgelist.begin(),edgelist.end());
	int mst_cost=0;
	initset(V);//in union find disjoint file
	for(int i=0;i<E;i++)
	{
		pair<int,pp> front=edgelist[i];
		if(!issameset(front.second.first,front.second.second))//means don't form cycle
		{
			mst_cost+=front.first;
			unionset(front.second.first,front.second.second);
		}
	}
	
	printf("%d",mst_cost);
	return 0;
}
