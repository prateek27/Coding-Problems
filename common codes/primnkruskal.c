#include<stdio.h>
#define INFINITY 9999

typedef struct{
	int weight[100][100];
	int arr[100];
	int n;
} Graph;

void Prim(int weight[][100], int n, int root)
{
	int distance[n], closest[n], current, i, j, mindist;
	for(i=0; i<n; i++)
	{
		distance[i]=weight[root][i];
		
		closest[i]=root;
	}
	distance[root]=INFINITY+1;
	current=root;
	for(i=1; i<n; ++i)
	{
		mindist=INFINITY;	
		for(j=0; j<n; j++)
		{
			if(distance[j]<mindist)
			{
				current=j;
				mindist=distance[j];
			}
		}
				printf("Edge%d: (%d,%d)\nCost: %d\n", i, closest[current], current, distance[current]);
		distance[current]=INFINITY+1;
		for(j=0; j<n; j++)
		{
			if(weight[current][j]!=INFINITY)
			{
				if((distance[j]<=INFINITY) && (weight[current][j]<distance[j]))
				{
					closest[j]=current;	
					distance[j]=weight[current][j];
				}	
			}
		}
	}
}

int checkUnion(int arr[], int n)
{
	int flag=0;
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(arr[j]!=arr[i])
			{
				flag=1;
				return flag;
			}
		}
	}
	if(flag==0)
	return flag;
}
	
void Kruskal(int weight[][100], int n)
{
	int forest[n], i, j, u, v;
	typedef struct{
		int edge;
		int n1, n2;
	} Edge;
	
	for(i=0; i<n; i++)
	forest[i]=i;

	int count=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(weight[i][j]!=INFINITY)
			{
				count++;
				weight[j][i]=INFINITY;
			}
		}
	}
	
	Edge edges[count];
	
	int k=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(weight[i][j]!=INFINITY)
			{
				edges[k].edge=weight[i][j];
				edges[k].n1=i;
				edges[k].n2=j;
				k++;
			}
		}
	}

	Edge temp;
	for(i=0; i<count; i++)
	{
		for(j=i; j<count; j++)
		{
			if(edges[i].edge>edges[j].edge)
			{
				temp=edges[i];
				edges[i]=edges[j];
				edges[j]=temp;
			}
		}
	}
	
	i=0;
	j=0;
	int val1, val2;
	while(checkUnion(forest, n))
	{
		u=edges[i].n1;
		v=edges[i].n2;
		if(forest[u]!=forest[v])
		{
			val1=forest[u];
			val2=forest[v];
			for(j=0;j<n; j++)
			{
				if(forest[j]==val2)
				forest[j]=val1;
			}
			printf("Edge %d: (%d, %d)\nCost: %d\n", i, u, v, edges[i].edge);
		}
		i++;
	}	
}	
void main()
{
	int i, j, root;
	Graph g;
	printf("Enter number of nodes: ");
	scanf("%d", &g.n);
	
	printf("Enter Weight Matrix: ");
	for(i=0; i<g.n; i++)
	{
		g.arr[i]=i;
		for(j=0; j<g.n; j++)
		{
			scanf("%d", &g.weight[i][j]);
			if(g.weight[i][j]==0)
			g.weight[i][j]=INFINITY;	
		}
	}

	printf("Enter root node: ");
	scanf("%d", &root);
	printf("Implementing Prim's Algorithm..\n");
	Prim(g.weight, g.n, root);

	printf("Implementing Kruskal's Algorithm..\n");
	Kruskal(g.weight, g.n);

}
