#include<iostream>
using namespace std;

void printMaze(char **maze,int n,int m){

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<maze[i][j];
    }
    cout<<endl;
}
cout<<endl;
}


bool isSafe(char** maze,int n,int m,int x,int y){


    //Obstacle or Out of bounds return false
    if(x>=n||y>=m||x<0||y<0)
        return false;

    if(maze[x][y]=='x')
        return false;

return true;
}




bool solveMaze(char **maze,int n,int m,int x,int y){

if(x==n-1&&y==m-1){
    if(maze[x][y]=='x'){
        return false;
    }

    maze[x][y] = '.';
    //printMaze(maze,n,m);
    return true;
}

    if(isSafe(maze,n,m,x,y)){

        maze[x][y] = '.';

        if(solveMaze(maze,n,m,x+1,y))
            return true;
        if(solveMaze(maze,n,m,x,y+1))
            return true;
        if(solveMaze(maze,n,m,x-1,y))
            return true;
        if(solveMaze(maze,n,m,x,y-1))
            return true;

         maze[x][y]='o';
         return false;
    }
    return false;
}


int main(){

int n,m,ch;
cin>>n>>m;


char **maze = new char*[n];
int i,j;

for(int i=0;i<n;i++){
    maze[i] = new char[m];
}


char *s = new char[100];
// Maze is of the form rows of oxoooxxx

for(i=0;i<n;i++){
    cin>>s;
    for(j=0;j<m;j++){
        maze[i][j]=s[j];
    }
}

if(solveMaze(maze,n,m,0,0)==false)
    cout<<"No Path found !";

else{
cout<<endl<<"Path found !"<<endl;
printMaze(maze,n,m);}


return 0;
}

