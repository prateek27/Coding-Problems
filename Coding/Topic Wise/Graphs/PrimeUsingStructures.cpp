#include<iostream>
#include<list>
using namespace std;
int costPrim[100][100];
int V;
int solution[100];

class Graph{

list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v,int w);
    void prim();

};

Graph::Graph(int V){
this->V=V;
adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
adj[v].push_back(w);
}

void Graph::prim(int s){
int myArray[100];
solution[0]=*adj[0];

list<int>::iterator j;
for(j=

}

int main(){
int i,j;
cin>>V>>E;

Graph myGraph(V);

for(i=0;i<V;i++){
    for(j=0;j<V;j++)
    {
     costPrim[i][j]=INF;
    }
}
for(k=0;k<E;k++)
{cin>>i>>j>>costPrim[i][j];
mygraph.addEdge(i,j);
}


return 0;
}
