#include<iostream>
#include<cstdio>
#include<list>
#include<climits>
using namespace std;

/* Given a directed graph with vertice V ( from 1 to N ) and
Edges E , the following program calcualtes the min no of edges to be reversed to establish
a path from vertex 1 to N */

class Graph{
int V,E;
list<int> *SAdj;
list<int> *RAdj;
public:
    Graph(int V,int E);
    void addSEdge(int u,int v);
    void addREdge(int u,int v);
    int calcMinEdges(int s);
};

Graph::Graph(int V,int E){
this->V = V;
this->E = E;
SAdj = new list<int>[V+1];
RAdj = new list<int>[V+1];
}

void Graph::addSEdge(int u,int v){
SAdj[u].push_back(v);
}

void Graph::addREdge(int u,int v){
RAdj[u].push_back(v);
}

int Graph::calcMinEdges(int s){

int dist[V+1];
    for(int i=2;i<=V;i++)
        dist[V]=INT_MAX;

list<int> q;
dist[s]=0;
q.push_back(s);
list<int>::iterator i,j;

while(!q.empty()){
        int s = q.front();
        q.pop_front();

        for(i=SAdj[s].begin();i!=SAdj[s].end();i++){
            if(dist[*i]>dist[s])
            {   dist[*i]=dist[s];
                q.push_back(*i);
            }
        }
        for(j=RAdj[s].begin();j!=RAdj[s].end();j++){
            if(dist[*j]>dist[s]+1)
            {   dist[*j]=dist[s]+1;
                q.push_back(*j);
            }
        }
}

if(dist[V]==INT_MAX)
    return -1;

else
    return dist[V];

}


int main(){
int V,E;
int u,v;
scanf("%d%d",&V,&E);
Graph g(V,E);
for(int i=0;i<E;i++){
    scanf("%d%d",&u,&v);
    g.addSEdge(u,v);
    g.addREdge(v,u);
}
printf("%d\n",g.calcMinEdges(1));

return 0;
}

