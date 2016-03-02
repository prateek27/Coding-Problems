#include<iostream>
#include<list>
#include<cstring>
using namespace std;

class Graph{


int V;
list<int> *adj;

    void DFSUtil(int v,bool *visited){
        visited[v]=true;
        cout<<v<<endl;

    for(auto it=adj[v].begin();it!=adj[v].end();it++){
            if(!visited[*it]){

                DFSUtil(*it,visited);
            }
        }
    }

public:

    Graph(int vertices){
    V = vertices;
    adj = new list<int>[V];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
    }


    void DFS(int v){
        bool *visited = new bool[V];

        memset(visited,false,sizeof(visited));

        //Start from the given vertext
        DFSUtil(v,visited);

        //If some of the vertexes are not convered , use this loop.
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFSUtil(i,visited);
            }
        }
    }

    void BFS(int v){

    list<int> q;
    q.push_back(v);
    bool *visited = new bool[V];
    memset(visited,false,sizeof(visited));

    while(!q.empty()){
        int f = q.front();

        cout<<f<<endl;
        visited[f]=true;
        q.pop_front();

        for(auto it=adj[f].begin();it!=adj[f].end();it++){
            if(visited[*it]==false)
                q.push_back(*it);
        }
    }

}


};
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"DFS"<<endl;
    g.DFS(2);
    cout<<"BFS"<<endl;
    g.BFS(2);
return 0;
}
