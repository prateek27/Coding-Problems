#include<iostream>
#include<queue>
using namespace std;


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
	adj[u][v] = 1;
}

void deleteEdge(int u,int v){
adj[u][v] = 0;
}

void BFS(){

bool visited[n];

for(int i=0;i<n;i++)
	visited[i] = false;

queue<int> q;
q.push(0);
visited[0] = true;

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
};

int main(){
Graph g(4);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(2,3);
g.BFS();

return 0;
}



