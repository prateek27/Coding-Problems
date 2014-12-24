#include<iostream>
using namespace std;



bool isSafe(int **board,int i,int col,int N){

int x,y;
//Case 1 : Straight left
x=i;y=col;
while(y>=0){
    y--;
    if(board[x][y]==1)
        return false;
}
//Case 2 : Up Left
x=i; y = col;
while(x>0&&y>0){
    x--;
    y--;
    if(board[x][y]==1)
     return false;
}

//Case 3 : Up Right
x=i; y = col;
while(x<N-1&&y>0){
    x++;
    y--;
    if(board[x][y]==1)
     return false;
}
//Else true in all cases
return true;
}


int countWays(int **board,int col,int n)
{

    if(col>=n){
        return 1;
    }

    int i;
    int count =0;
    for(i=0;i<n;i++){

    //Check if the given position is safe to place the queen , the place the queen ,check for next ! :D
    if(isSafe(board,i,col,n)){
        board[i][col]=1;//Place the Queen
        count += countWays(board,col+1,n);
        board[i][col]=0; //Backtrack
        }
    }
    return count;
}

int main(){
int n,i,j;
cin>>n;

int **board = new int*[n];

for(i=0;i<n;i++)
    board[i] = new int[n];

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        board[i][j]=0;

cout<<"The No of ways "<<n<<" queens can be placed on a "<<n<<" X "<<n<<" chessboard is :"<<endl<<countWays(board,0,n);

return 0;
}
