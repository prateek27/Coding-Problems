#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V){ this->V=V; adj=new list<int>[V];}
    ~Graph() { delete []adj;}
    void addEdge(int v,int w);
    void greedyColoring();
};
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::greedyColoring(){
int result[V];

for(int i=0;i<V;i++) result[i]= -1;  // -1 means all are colorless

bool available[V];                            //at max V color can be used .All unused initiallly
for(int i=0;i<V;i++) available[i]=false;

list<int>::iterator i;
int u;
for(u=0;u<V;u++){

    for(i=adj[u].begin();i!=adj[u].end();i++)
        {
         if(result[*i]!=-1) available[result[*i]]=true; //true means color has been used
        }
   int clr;
    for(clr=0;clr<V;clr++)  //fomd tje first available color
        if(available[clr]==false)
        break;

    result[u]=clr;

for(i=adj[u].begin();i!=adj[u].end();i++)
        if(result[*i]!=-1) available[result[*i]]=false;

}
//print
for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;


}

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of Graph 1 \n";
    g1.greedyColoring();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of Graph 2 \n";
    g2.greedyColoring();

    return 0;
}
