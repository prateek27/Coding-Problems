//Adjacency matrix used			O(E*V^3)

#define MAX_V 100
int res[MAX_V][MAX_V],mf,f,s,t;
//res is residual matrix,mf=maximum flow f=minimum residual capacity s=source t=sink
vi p;
void augment(int v,int minedge)//v is edge index,minedge is min residual capacity along path
{
	if(v==s)
	{
		f=minedge;
		return;
	}
	else if(p[v]!=-1)//p[v] is -1 if no s found
	{
		augment(p[v],min(minedge,res[p[v]][v]));
		res[p[v]][v]-=f;	//subtract flow along the path
		res[v][p[v]]+=f;	//add flow opposite to path
	}
	
}
mf=0;
while(1)
{
	f=0;
	vi dist(MAX_V,INF);dist[s]=0;queue<int> q;q.push(s);
	p.assign(MAX_V,-1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==t)	break;
		for(int v=0;v<MAX_V;v++)
			if(res[u][v]>0 && dist[v]==INF)
				dist[v]=dist[u]+1,q.push(v),p[v]=u;
	}
	augment(t,INF);
	if(f==0)		//no flow is possible. Logically if f=0,means in bfs only one loop for u=s is executed. means every edge from source has res<=0
		break;
	mf+=f;	
}
printf("%d",mf);
