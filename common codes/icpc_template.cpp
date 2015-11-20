#include <iostream>
#include <stdio.h>
#include <algorithm>
#include<list>
#include<utility>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <assert.h>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include <stack>
#include <vector>
#include <map>
#include <time.h>
#include <climits>

using namespace std;
typedef long long ll ;
typedef vector<ll> VI ;
typedef pair<ll,ll>  PP;
typedef vector<PP>  VPP ;
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n", a)
#define f(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define mx 1000000010
#define siz 1000010
#define  MP make_pair
#define pb push_back
#define F first
#define S second
#define inf 0x7fffffff

const int mod = 1e9 + 7 ;
int powmod(ll a,int b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b); }
ll t,n,k,i,j,x,y,m,g;

struct item{
	ll x;
	ll y;
};

bool compare(item a,item b)
{	return a.x<b.x;}

/*
ll find1(ll l, ll h, ll q)
{
	ll mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(d[mid].x==q && d[mid+1].x>q)return mid;
		else if(d[mid].x<=q)l=mid+1;
		else h=mid-1;
	}
	return -1;
}

ll find2(ll l, ll h, ll q)
{
	ll mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(d[mid].x>=q && d[mid-1].x<q)return mid-1;
		else if(d[mid].x<q && d[mid+1].x>=q) return mid;
		else if(d[mid+1].x<q)l=mid+1;
		else h=mid-1;
	}
	return -1;
}

ll find3(ll l, ll h, ll q)
{
	ll mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(d[mid].x>q && d[mid-1].x<=q)return mid-1;
		else if(d[mid].x<=q && d[mid+1].x>q) return mid;
		else if(d[mid+1].x<=q)l=mid+1;
		else h=mid-1;
	}
	return -1;
}
*/

int main() {
	sl(t);
	while(t--){
	sl(n);
	f(i,n){

	}
	}
	return 0;
}
