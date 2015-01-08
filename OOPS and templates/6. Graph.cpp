#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INT_MAX 1000000
#define INT_MIN -1000000

struct edge{
    int u,v,wt;
};


bool compareEdge(edge e1,edge e2){
    return e1.wt < e2.wt;
}

/*
---------------------------------------------------------------------------------------------------------------------------
5. Implement Graph Class for unweighted Graph with Adjacency Matrix with
following functions
a. Add Edge
b. Delete Edge
c. BFS
d. DFS
e. Topological Sort
f. Minimum Spanning Tree
g. All Pair Shortest Path
h. Detect Cycle
i. Print Shortest Path from Src to Dest
j. Print All Possible path from source to destination
k. Check if Graph is Bipartitie or Not
l. Find all connected Components

*/

class Graph{
int **adj;
int n;
private:
	void DFSHelper(int index,bool *visited){
			cout<<index <<" ";
			visited[index] = true;
			for(int i =0; i<n ; i++) {
				if(!visited[i] && adj[index][i] == 1) {
					DFSHelper(i , visited);
				}
			}
		}
public:
	Graph(int n){

	this->n = n;
	adj = new int*[n];

	for(int i=0;i<n;i++){
    adj[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
            }
        }
    }
void addEdge(int u,int v){
	 //For directed unweighted graph
        adj[u][v] = 1;
    }
void addEdge(int u,int v,int wt){
        //For undirected weighted graph
        adj[u][v]=wt;
        //adj[v][u]=wt;
    }

void deleteEdge(int u,int v){
}

void BFS(){

bool visited[n];

for(int i=0;i<n;i++)
	visited[i] = false;

queue<int> q;

for(int i=0;i<n;i++){

if(!visited[i]){
q.push(i);
visited[i] = true;

    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for( int v= 0 ;  v<n ; v++){
                if (adj[u][v] == 1 && !visited[v]){
                        q.push(v);
                        visited[v] = true;
                        }
                    }
                }
            }
        }
    }
//----------------------------DFS
void DFS(){
bool visited[n] ;
int i;
for( i = 0; i<n;i++){
	visited[i] = false;
}
    for(i=0;i<n;i++){
	if(!visited[i])
		DFSHelper(i,visited);
        }
    }
//------------------------------Topological Sort
void TopologicalSort(){
int indegree[n];

for(int i=0;i<n;i++){
indegree[i] = 0;
}
int i,j;

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(adj[i][j] ==1){
			indegree[j]++ ;
            }
        }
    }
//So Let’s start with code
queue<int> q;
//Let’s find the nodes with 0 indegree first
for(int i=0;i<n;i++){

	if(indegree[i]==0)
		{
        q.push(i);

		}

}

while(!q.empty()){
	int u = q.front();
	cout<<u<<" ";
	q.pop();
	for(int v=0;v<n;v++){
	 	if(adj[u][v] ==1){
		indegree[v]--;
	if(indegree[v]==0)
		q.push(v);
            }
        }
    }
cout<<endl;
}
//-------------------------------Prims MST
void primsMST(){
    bool visited[n];
    int dist[n];
    int parent[n];
    int i;
    for(i=0;i<n;i++)
        visited[i] = false;

    for(i=0;i<n;i++)
        dist[i] = INT_MAX;

    dist[0] = 0;
    parent[0] = 0;

    int count = n-1;
    //On each loop a vertex is included in MST
    while(count--){
        int min_dist = INT_MAX;
        int min_vertex=0;
        for(i=0;i<n;i++){
            if(visited[i]==false && dist[i]<=min_dist)
            {
                min_vertex =i;
                min_dist = dist[i];
            }
        }
        visited[min_vertex] =true;
        int u = min_vertex;
        for(int v=0;v<n;v++)
        {
        if(adj[u][v]!=0&&!visited[v]){
            if(dist[v]>adj[u][v]){
                    dist[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

    }
    //Print MST
    cout<<"Edges :"<<"Weight "<<endl;
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" "<<adj[parent[i]][i]<<endl;
    }
}
//------------------------------------------Kruskal's algorithm
void krusksalMST(){

    vector<edge> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]!=0){
                edge e;
                e.u = i ; e.v = j; e.wt = adj[i][j];
                v.push_back(e);

            }
        }
    }
    cout<<"Size is "<<v.size()<<endl;
    sort(v.begin(),v.end(),compareEdge);

    /*
    cout<<"After Sorting ";
    for(int i=0;i<v.size();i++){
        cout<<v[i].wt<<endl;
    }
    cout<<endl;
    */

    bool visited[n];

    for(int i=0;i<n;i++)
        visited[i] = false;

    vector<edge> mstEdges;
    int count = 0;
/* WRONG LOGIC */
    for(int j=0;j<v.size();j++){
        int x = v[j].u;
        int y = v[j].v;

        if(visited[x]==false||visited[y]==false)
        {   count++;
            visited[x] = true;
            visited[y] = true;
            mstEdges.push_back(v[j]);
        }

    }

    for(int i=0;i<mstEdges.size();i++){
        cout<<mstEdges[i].u<<" - "<<mstEdges[i].v<<" : "<<mstEdges[i].wt<<endl;
    }


    }
void allPairShortestPath(){
//This is a floyd warshall algorithm
int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(i==j)
                    dist[i][j]=0;
                else if(adj[i][j]==0)
                    dist[i][j] = INT_MAX;
                else{
                    dist[i][j] = adj[i][j];
                }
            }
        }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
            }

        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(dist[i][j]!=INT_MAX)
                cout<<dist[i][j]<<" ";
            else
                cout<<"INF ";
        }
        cout<<endl;
    }

    }
};
int main(){
Graph g(5);

g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(2,1);
g.addEdge(2,3);
cout<<"BFS :"<<endl;
g.BFS();
cout<<endl;
cout<<"DFS :"<<endl;
g.DFS();
cout<<endl;

    Graph g2(6);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    cout<<"Topological Sort : "<<endl;
    g2.TopologicalSort();
// 5 4 2 3 1 0

Graph g3(5);
g3.addEdge(0,1,2);
g3.addEdge(1,2,3);
g3.addEdge(2,4,7);
g3.addEdge(1,4,5);
g3.addEdge(3,4,9);
g3.addEdge(1,3,8);
g3.addEdge(0,3,6);
cout<<"Prims MST "<<endl;
//g3.primsMST();
Graph g4(9);
g4.addEdge(0,1,4);
g4.addEdge(0,7,8);
g4.addEdge(1,7,11);
g4.addEdge(1,2,8);
g4.addEdge(2,3,7);
g4.addEdge(2,8,2);
g4.addEdge(2,5,4);
g4.addEdge(3,5,14);
g4.addEdge(3,4,9);
g4.addEdge(4,5,10);
g4.addEdge(5,6,2);
g4.addEdge(6,8,6);
g4.addEdge(6,7,1);
g4.addEdge(7,8,7);
cout<<"Prim's MST : "<<endl;
g4.primsMST();
cout<<endl<<"Kruskal's MST "<<endl;
g4.krusksalMST();
/* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9
*/

cout<<"Floyd Warshall "<<endl;
g4.allPairShortestPath();

Graph g5(4);
g5.addEdge(0,3,10);
g5.addEdge(0,1,5);
g5.addEdge(1,2,3);
g5.addEdge(2,3,1);
    /*  10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
            */
g5.allPairShortestPath();
return 0;
}






