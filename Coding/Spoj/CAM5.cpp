#include<iostream>
#include<cstdio>
#include<list>
#define si(n) scanf("%d",&n);
using namespace std;

class Graph{
int V;
list<int> *adj;
void DFSUtil(int v,bool visited[]);
public:
    Graph(int V);
    void addEdge(int u,int v);
    void DFS(int s);
};

Graph::Graph(int V){
this->V = V ;
adj = new list<int>[V];
}


void Graph::DFS(int V){

bool *visited = new bool[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            {
            count++;
            DFSUtil(i,visited);
            }
        }
printf("%d\n",count);
}

void Graph::addEdge(int u,int v){
adj[u].push_back(v);
adj[v].push_back(u);
}

void Graph::DFSUtil(int v,bool visited[]){
visited[v]=true;
list<int> :: iterator i;
int count=0;
for(i=adj[v].begin();i!=adj[v].end();i++){
    if(!visited[*i]){
        DFSUtil(*i,visited);
        }
    }
}

int main(){
int t;
si(t);
while(t--)
{ int v;
  si(v);
  Graph g(v);
  int n;
  si(n);
  for(int i=0;i<n;i++){
  int u,v;
  si(u);si(v);
  g.addEdge(u,v);
  }
 g.DFS(v);
}
return 0;
}
