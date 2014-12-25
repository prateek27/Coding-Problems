#include<iostream>
using namespace std;

void printGrid(char grid[100][100],int n,int m){
    static int gridNo = -1;

    gridNo++;
    if(gridNo==0){
    cout<<"Original Grid :"<<endl;
    }
    else{
    cout<<"Grid Formed :"<<gridNo<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
    cout<<endl;
    }
cout<<endl;
}
//-----------------------------------------Writing two functions
//1. To Print a the first  Path found
//2. To Print All Possible Paths

bool findFirstPath(char grid[100][100],int n,int m,int x,int y){


    if(x==n-1&&y==m-1){
        grid[x][y]='*';
        printGrid(grid,n,m);
        grid[x][y]='o';
        return true;
    }
    if(x<m&&y<n){
        grid[x][y]='*';

        //By Returning it terminates
        if(findFirstPath(grid,n,m,x+1,y))
            return true;

        //Terminate if path is found
        if(findFirstPath(grid,n,m,x,y+1))
            return true;

        //Else Backtrack
        grid[x][y]='o';
        return false;
    }
    //Not a valid position , return false
    return false;
}
//------------------------------------------------------------------This function tries all possible paths ,dont use return statement


bool findPaths(char grid[100][100],int n,int m,int x,int y){

    if(x==n-1&&y==m-1){
        grid[x][y]='*';
        printGrid(grid,n,m);
        grid[x][y]='o';
        return true;
    }
    if(x<m&&y<n){
        grid[x][y]='*';

        findPaths(grid,n,m,x+1,y);

        findPaths(grid,n,m,x,y+1);


        grid[x][y]='o';
        //return false;
    }
    return false;
}

void initGrid(char grid[][100],int n,int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            grid[i][j] = 'o';
        }
    }
}


int main(){
int n,m,right=0,down=0;
int moves[10000];

cout<<"Enter Grid Size";
cin>>n>>m;
char grid[100][100];
initGrid(grid,n,m);
printGrid(grid,n,m);
//Decomment to test this fucntion
//findFirstPath(grid,n,m,0,0);
findPaths(grid,n,m,0,0);

return 0;
}
