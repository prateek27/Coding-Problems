#include<iostream>
#include<cstdio>
#include<list>
using namespace std;
class Graph{
int V;

list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u,int w);
    void BFS(int s);
};
Graph::Graph(int V){
this->V=V;
}

void Graph::addEdge(int u,int w){
adj[u].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
   for(int i=0;i<V;i++)
    visited[i]=false;

    visited[s]=true;
    list<int> queue;
    queue.push_back(s);

    list<int>::iterator i;
   while(!queue.empty()){

        s=queue.front();

        cout<<s<<" ";
        queue.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++){
            if(visited[*i]==false)
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }

   }
}
int main(){

Graph g = Graph(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(0,3);
g.addEdge(1,2);
g.addEdge(2,5);
g.addEdge(3,5);
g.BFS(0);
return 0;
}
