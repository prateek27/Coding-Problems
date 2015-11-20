#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int dfs(char m[22][22], int i,int j);

struct node
{
	int r,c;
};
typedef struct node Node;
Node newnode(int row,int col)
{
	Node n;
	n.r=row;
	n.c=col;
	return n;
}
int M,N,ans;
void dfsb(char m[22][22],stack<Node> Q,bool visited[22][22]);
int main()
{
	
	int i,count,t;
	scanf("%d",&t);
	while(t--)
	{
	
	char m[22][22];
	int done[22][22]={0},flag=0;
	scanf("%d %d",&M,&N);
	for(i=0;i<M;i++)
		scanf("%s",m[i]);
	count=0;	
	for(i=0;i<N;i++)	
		{
			if(m[0][i]=='.'&& !done[0][i])
				{
				if(dfs(m,0,i)==2)
					count++;
				else {
				flag=-1;	
				break;}
				done[0][i]=1;
				}
			if(m[M-1][i]=='.'&&!done[M-1][i])
				{
				 if(dfs(m,M-1,i)==2)
					count++;
				 else {
				flag=-1;	
				break;}		
				done[M-1][i]=1;
				}
	  	}
	for(i=0;i<M;i++)	
		{
			if(m[i][0]=='.'&&!done[i][0])
				{
				if(dfs(m,i,0)==2)
					count++;
				else {
				flag=-1;	
				break;}	
				done[i][0]=1;
			   }
			if(m[i][N-1]=='.'&&!done[i][N-1])	
				{
				if(dfs(m,i,N-1)==2)
					count++;
				else {
				flag=-1;	
				break;}	
				done[i][N-1]=1;	
				}
				
		}
	if(count!=2 || flag==-1)		
		printf("invalid\n");
	else
		printf("valid\n");	
	}
	return 0;
}
int dfs(char m[22][22], int i,int j)
{
	bool visited[22][22];
	for(int l=0;l<22;l++)
		for(int n=0;n<22;n++)			/*Not accepted without this loop*/
			visited[l][n]=false;
	ans=0;
	stack<Node> Q;
	Q.push(newnode(i,j));
	visited[i][j]=true;
	dfsb(m,Q,visited);
	return ans;	
}
void dfsb(char m[22][22],stack<Node> Q,bool visited[22][22])
{
		Node *cur=&(Q.top());
		if(cur->r==0||cur->r==M-1||cur->c==0||cur->c==N-1)
		{
			ans++;
		}	
		
		if(!visited[cur->r][cur->c-1]&&m[cur->r][cur->c-1]=='.' && cur->c-1>=0)
			{
				visited[cur->r][cur->c-1]=true;
				Q.push(newnode(cur->r,cur->c-1));
				dfsb(m,Q,visited);
			}
		if(!visited[cur->r][cur->c+1]&&m[cur->r][cur->c+1]=='.'&&cur->c+1<N)
			{
				visited[cur->r][cur->c+1]=true;
				Q.push(newnode(cur->r,cur->c+1));
				dfsb(m,Q,visited);
			}
		if(!visited[cur->r-1][cur->c]&&m[cur->r-1][cur->c]=='.'&&cur->r-1>=0)
			{
				visited[cur->r-1][cur->c]=true;
				Q.push(newnode(cur->r-1,cur->c));
				dfsb(m,Q,visited);
			}
		if(!visited[cur->r+1][cur->c]&&m[cur->r+1][cur->c]=='.'&&cur->r+1<M)
			{
				visited[cur->r+1][cur->c]=true;
				Q.push(newnode(cur->r+1,cur->c));
				dfsb(m,Q,visited);
			}
		Q.pop();	
}
	


