// http://codeforces.com/contest/540/problem/C

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
int n,m,r1,c1,r2,c2,f=0;
char c[505][505];

void dfs(int x,int y)
{
    if(x>n||x<1||y>m||y<0)
    	return;
    if(c[x][y]!='.'&&!(x==r2&&y==c2))return;
    
    if(x==r2&&y==c2&&c[x][y]=='X')
    {
        f=1;return;
    }
    c[x][y]='X';
    dfs(x,y+1);dfs(x,y-1);dfs(x+1,y);dfs(x-1,y);
}

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>c[i][j];
	cin>>r1>>c1>>r2>>c2;
	c[r1][c1]='X';
	dfs(r1+1,c1);dfs(r1-1,c1);dfs(r1,c1+1);dfs(r1,c1-1);
	if(f)
		cout<<("YES");
	else
		cout<<("NO");
	return 0;
}
