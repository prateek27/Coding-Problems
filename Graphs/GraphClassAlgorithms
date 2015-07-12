#include<iostream>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;

/* Author : Prateek Narnag */

/* Problem Statement : 5. Implement Graph Class for unweighted Graph with Adjacency Matrix with
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
#define INT_MAX 100000
class Graph{
    int **adj;
    int n;
    void DFSHelper(int i,bool *visited);
    int pickMinimum(int *dist,bool *mstSet);
public:
    Graph(int n);
    void addEdge(int u,int v);
    void addEdgeWeight(int u,int v,int w);
    void deleteEdge(int u,int v);
    void BFS(int s);
    void DFS(int s);
    void TopologicalSort();
    void MSTPrim();
    void MSTKruksal();
    bool detectCycle();
    void printShortestPath();
    void printAllPossiblePath();
    void findConnected();
    bool isBipartite();
    ~Graph(){
        delete adj;
        adj=NULL;
    }
};

Graph::Graph(int n){
    this->n = n;
    adj = new int*[n];
    for(int i=0;i<n;i++){
        adj[i]=new int[n];
    }
    //Initialise the 2D Matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            adj[i][j] = 0;
        }

    }
}
void Graph::addEdge(int u,int v)
{
    adj[u][v]=1;
}
void Graph::addEdgeWeight(int u,int v,int w){
adj[u][v]=w;
}
void Graph::deleteEdge(int u,int v){
adj[u][v]=-1;
}


void Graph::BFS(int s){
bool visited[n];
queue<int> q;

    for(int i=0;i<n;i++){
    visited[i]=false;
    }

    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<<temp<<",";

        for(int i=0;i<n;i++){
            if(adj[temp][i]>0&&!visited[i])
            {
                visited[i]=true;
                q.push(i);
                //cout<<"PUSHED"<<i<<endl;
            }
        }
    }
return;
}
void Graph::DFS(int s){

bool *visited = new bool[n];

for(int i=0;i<n;i++){
    visited[i]=false;
}
//Make the first call from the source given


for(int i=0;i<n;i++){
    if(!visited[i])
            {  cout<<"Calling "<<i;
                DFSHelper(i,visited);}
    }
}

void Graph::DFSHelper(int i,bool* visited){
    visited[i]=true;
    cout<<i<<", ";



    for(int j=0;j<n;j++){
            if(!visited[j]&&adj[i][j]>0){
                //cout<<"on edge"<<i<<","<<j<<endl;
                DFSHelper(j,visited);
                }
            }
}

void Graph::TopologicalSort(){
int *indegree = new int[n];
memset(indegree,0,n);
queue<int> q;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(adj[i][j]>0){
            indegree[j]++;
        }
    }
}

for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
while(!q.empty()){
    int temp = q.front();
    cout<<temp<<" ,";
    q.pop();
    for(int i=0;i<n;i++){
        if(adj[temp][i]>0){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
                }
            }
        }

    }
}

int Graph::pickMinimum(int *dist,bool *mstSet){
    int min_index=-1;
    int min_distance=INT_MAX;
    int i;
    for(i=0;i<n;i++){
          if(dist[i]<min_distance&&mstSet[i]==false){
            min_index=i;
            min_distance=dist[i];
          }
    }
return min_index;
}

void Graph:: MSTPrim(){
    int *parent = new int[n];
    int *dist = new int[n];
    bool *mstSet = new bool[n];

    for(int i=0;i<n;i++){
        mstSet[i]=false;
        dist[i] = INT_MAX;
    }

    dist[0]=0;
    parent[0]=-1;


    int u;
    //Pick one vertex everytime. 0th already picked.
    for(int i=0;i<n-1;i++){

        int u=this->pickMinimum(dist,mstSet);
        mstSet[u]=true;
        for(int j=0;j<n;j++){
                //NOte this PART ! DONT CONFUSE WITH DIJKSHTRA's
            if(adj[u][j]&&mstSet[j]==false&&adj[u][j]<dist[j]){
                dist[j]=adj[u][j];
                parent[j]=u;
            }
        }
    }
    cout<<"Vertext - Distance - Parent "<<endl;
    for(int i=0;i<n;i++){
            cout<<i<<" ,"<<dist[i]<<" ,"<<parent[i]<<endl;
        }


}



int main(){

Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,2);
g.addEdge(2,3);
g.BFS(1);
cout<<endl;

cout<<"DFS for G1 : ";
g.DFS(0);
cout<<endl;

Graph g2(6);
g2.addEdge(5, 2);
g2.addEdge(5, 0);
g2.addEdge(4, 0);
g2.addEdge(4, 1);
g2.addEdge(2, 3);
g2.addEdge(3, 1);

cout<<"BFS for G2 :";
g2.BFS(5);
cout<<endl;

cout<<"DFS for G2 : ";
g2.DFS(5);
cout<<endl;


 Graph g3(6);
    g3.addEdge(5, 2);
    g3.addEdge(5, 0);
    g3.addEdge(4, 0);
    g3.addEdge(4, 1);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);
cout<<"Topological Sort";
g3.TopologicalSort();
cout<<endl;

Graph g4(5);
g4.addEdgeWeight(0,1,2);
g4.addEdgeWeight(1,0,2);
g4.addEdgeWeight(1,2,3);
g4.addEdgeWeight(2,1,3);

g4.addEdgeWeight(2,4,7);
g4.addEdgeWeight(4,2,7);
g4.addEdgeWeight(1,4,5);
g4.addEdgeWeight(4,1,5);

g4.addEdgeWeight(3,4,9);
g4.addEdgeWeight(4,3,9);
g4.addEdgeWeight(1,3,8);
g4.addEdgeWeight(3,1,8);


g4.addEdgeWeight(0,3,6);
g4.addEdgeWeight(3,0,6);
cout<<"Prim's MST :";
g4.MSTPrim();
cout<<endl;
return 0;
}
