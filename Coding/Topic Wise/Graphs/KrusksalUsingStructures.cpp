#include<iostream>
#include<algorithm>
using namespace std;

struct graph{    //Store the edges
int v,w;
int weight;
};

struct parent{  //Store parents
int p;
};


void kruskal(struct graph a[],int E,struct parent allparents[])
{
int i; int mst=0;


for(i=0;i<E;i++)
{
    if(allparents[a[i].v].p!=allparents[a[i].w].p)   //IF parents are different add the that edge
    {
        mst+= a[i].weight;
        allparents[a[i].w].p=allparents[a[i].v].p;
        cout<<a[i].v<<"->"<<a[i].w<<endl;
    }

}

cout<<" Minimum weight "<<mst;
return ;
}


void bubbleSort(struct graph a[],int N){
int i,j;
for(i=0;i<N-1;i++)
{
    for(j=i+1;j<N;j++)
    {
        if(a[j].weight<a[i].weight)          //Sort on the weight basis
        {
            int temp = a[i].weight;          //Swap wts , x, y cooordinates
            a[i].weight=a[j].weight;
            a[j].weight=temp;

            temp=a[i].v;
            a[i].v=a[j].v;
            a[j].v=temp;

            temp=a[i].w;
            a[i].w=a[j].w;
            a[j].w=temp;
        }
    }
}
return ;
}



int main(){
int i,V,E;

cout<<" Enter vertices and edges ";
cin>>V>>E;
int vertices[V];


graph mygraph[E];
parent allparents[V];
//Initialize parents
for(i=0;i<V;i++)
{
    allparents[i].p = i;
}



cout<<"Enter edges and weights ";
for(i=0;i<E;i++)
{
    cin>>mygraph[i].v>>mygraph[i].w>>mygraph[i].weight;
}

bubbleSort(mygraph,E);
kruskal(mygraph,E,allparents);


return 0;
}
