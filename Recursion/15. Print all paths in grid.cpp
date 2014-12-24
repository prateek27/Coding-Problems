#include<iostream>
using namespace std;

//Buggy

void printGrid(char grid[100][100],int n,int m){
    static int gridNo = 0;

    gridNo++;
    cout<<"Grid :"<<gridNo<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
    cout<<endl;
    }
cout<<endl;
}


void findPaths(char grid[100][100],int n,int m,int right ,int down){

    if(right==m&&down==n){
        printGrid(grid,n,m);
        return;
    }

    if((right==m&&down!=n)||(right!=m&&down==n))
    {
        grid[down][right]='o';
    }

    if(right<m){
        grid[down][right]='*';
        findPaths(grid,n,m,right+1,down);



    }
    if(down<n){
        grid[down][right]='*';
        findPaths(grid,n,m,right,down+1);


    }
    grid[down][right]='o';

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
findPaths(grid,n,m,right,down);

return 0;
}
