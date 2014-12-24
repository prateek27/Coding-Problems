#include<iostream>



void solveMazeBFS(){


}

int main(){
char **maze = new *char[n];
int n,m;
cin>>n>>m;

int i,j;
for(int i=0;i<n;i++){
    maze[i] = new char[m];
}

// Maze is of 0*
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        cin>>maze[i][j];
    }
}

solveMaze(maze,n,m);
return 0;
}
