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
adj[u][v] = 0;
	adj[u][v] = 1;
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

void TopologicalSort(){
int indegree[n];

for(int i=0;i<n;i++){
indegree[n] = 0;
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
		q.push(i);

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
}



};

int main(){
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(2,1);
g.addEdge(2,3);
g.BFS();
cout<<endl;
g.DFS();


Graph g2(6);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    g2.TopologicalSort();
// 5 4 2 3 1 0
return 0;
}






