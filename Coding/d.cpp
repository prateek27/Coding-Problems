#include<iostream>
#include<list>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int dist[100005];
class Graph{
int V;
list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
};

Graph::Graph(int V){
this->V=V;
adj = new list<int>[V];
}
void Graph::addEdge(int v,int w){
adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        {visited[i] = false;
         dist[i]=100000000;
        }
        dist[s]=0;
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
       // cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i]&&dist[*i]>dist[s]+1)
            {
                visited[*i] = true;
                dist[*i]=dist[s]+1;
                queue.push_back(*i);
            }
        }
    }
}


int main(){
int i,j,n;

char  s[100005];
scanf("%s",&s);

int len=strlen(s);
vector<int> v[10];
//bool dp[100005][10];

for(i=0;i<len;i++){
    int a = s[i]-'0';
    v[a].push_back(i);
//    while(s[i]==s[i+1])
  //      i++;
}

Graph g(len);
for(i=0,j=len;i<len-1;i++,j--)
{
//cout<<"Edge Inserted "<<i<<"-"<<i+1<<endl;
g.addEdge(i,i+1);
}

for(j=len-1;j>0;j--)
{
    g.addEdge(j,j-1);
//    cout<<"Edge Inserted "<<j<<"-"<<j-1<<endl;


}

int k;
for(i=0;i<10;i++){
        for(j=0;j<v[i].size();j++)
        {
            for(k=j+1;k<v[i].size();k++)
            {
                g.addEdge(v[i][j],v[i][k]);
                //cout<<"Edge Inserted "<<v[i][j]<<"-"<<v[i][k]<<endl;

            }
        }

}
g.BFS(0);
printf("%d",dist[len-1]);
return 0;
}
