#include<iostream>
using namespace std;
int adjMatrix[20][20];
int q[20];
int visited[20];
int f=0,r=-1,n;

void bfs(int v)
{ int i;
    for(i=1;i<=n;i++)
      if(adjMatrix[v][i] && !visited[i])
       q[r++]=i;

      if(f<=r)
      {
      visited[q[f]]=1;
      bfs(q[f++]);
      }
}


int main()
{
int i,j;
char v;
cout<<"Enter the number of vertices : ";
cin>>n;
cout<<"Enter the info of vertices : ";

cout<<"Enter the data in adjacency matrix in 0s/1s "<<endl;
cout<<"  ";
for(i=1;i<=n;i++) cout<<" "<<i;  cout<<endl;
for(i=1;i<=n;i++)
{
    cout<<i<<"  ";
    for(j=1;j<=n;j++) {  cin>>adjMatrix[i][j]; }

}


bfs(1);
for(i=1;i<=n;i++)
	 	 if(visited[i])
	   		cout<<i<<" " ;
	  	 else{
   		 cout<<"BFS not possible";
         break;
	  	 }

return 0;
}
