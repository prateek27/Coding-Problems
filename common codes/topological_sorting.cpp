#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
vi topsort;
void dfs2(int u)
{
	dfs_num[u]=1;
	for(int j=0;j<(int)adjlist[u].size();j++)
	{
		ii v=adjlist[u][j];
		if(dfs_num[v.first]==0)
			dfs2(v.first);
	}
	topsort.push_back(u);
}

int main()
{
int V;
topsort.clear();
memset(dfs_num,0,sizeof dfs_num);
for(int i=0;i<V;i++)
	if(dfs_num==0)
		dfs2(i);
reverse(topsort.begin(),topsort.end());
for(int i=0;i<(int)topsort.size();i++)
	printf("%d ",topsort[i]);
return 0;
}
			
