#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int getMinimum(int *dist,bool *marked,int v){
int d = INT_MAX;int vertex,i;
for(i=0;i<v;i++){
    if(marked[i]==false&&dist[i]<d){
    vertex = i;
    d = dist[i];
        }
    }
return vertex;
}

void dijkstra(int g[9][9],int s,int v){
bool marked[v+1];
int dist[v+1];

for(int i=0;i<v;i++)
{ marked[i]=false ; dist[i]= INT_MAX ;}

dist[s]=0;
int cnt;

for(cnt=1;cnt<=v-1;cnt++){
int u = getMinimum(dist,marked,v);
marked[u]= true;
for(int i=0;i<v;i++){
        if(marked[i]==false && g[u][i]!=0 && g[u][i]+dist[u]<dist[i])
            dist[i]=dist[u]+g[u][i];
    }
}

for(int i=0;i<v;i++){
cout<<i<<" "<<dist[i]<<endl;
}

}


int main(){
//Given a matrix
        int v=9 ;
     int graph[][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0 ,v);

return 0;
}
