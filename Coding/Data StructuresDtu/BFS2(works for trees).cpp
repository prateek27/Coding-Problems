#include<iostream>
using namespace std;

char queue[20];
int front=0,rear=0;
char array[20] ;
int adjMatrix[20][20];
int bfs(int);
char b[20];
int p=0,n;
int main()
{
int i,j;
char v;
cout<<"Enter the number of vertices : ";
cin>>n;
cout<<"Enter the info of vertices : ";
for(i=0;i<n;i++)
{
    cin>>b[i];
}
cout<<"Enter the data in adjacency matrix in 0s/1s "<<endl;
cout<<"  ";
for(i=0;i<n;i++) cout<<" "<<b[i];  cout<<endl;
for(i=0;i<n;i++)
{
    cout<<b[i]<<"  ";
    for(j=0;j<n;j++) {  cin>>adjMatrix[i][j]; }

}
for(int i=0;i<n;i++) { bfs(i);}

for(i=0;i<n;i++) { cout<<array[i]<<" ";}

return 0;
}

void insert(char value)
{
    queue[rear++]=value;
}
char del()
{
    return queue[front++];
}

bool unVisit(char value)
{
    for(int i=0;i<front;i++)
        if(value==queue[i])
        return false;
    return true;
}

int bfs(int i)
{
char m;int j;
if(front==0)
    insert(b[i]);

    for(j=0;j<n;j++)
    {
        if(adjMatrix[i][j]==1){
            if(unVisit(b[j]))
               insert(b[j]);}
    }
m=del();
array[p++]=m;
return 0;
}

