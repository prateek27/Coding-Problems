#include<iostream>
using namespace std;


struct coord{
int x;
int y;
}


void BFS(int**maze,int m,int n,coord start,coord dest){
        int **output = new int*[m];
        for(int i=0;i<m;i++){
            output[i] = new int[n];
        }
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                output[i][j]= maze[i][j]?-1:0;
            }
        }

        queue<coord> q;
        q.push(start);

        while(q.empty()){


        }


return 0;
}



int main(){
cin>>m>>n;
int i,j;

int **maze = new int[m];

for(i=0;i<m;i++){
    maze[i] = new int[n];
}

for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        cin>>maze[i][j];
    }
}

return ;
}
