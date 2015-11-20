#include<iostream>
using namespace std;

int board[100][100];
int N;

void printboard(){
int i,j;
for(i=0;i<N;i++){
    for(j=0;j<N;j++)
    {
    cout<<board[i][j]<<" ";
    }
cout<<endl;
}

}


bool isSafe(int row,int col){
int i,j;

for(i=0;i<N;i++)
    if(board[row][i]==1)
    return false;

for(i=row,j=col;i>=0,j>=0;i--,j--)
      if(board[i][j]==1)
        return false;

for(i=row,j=col;i<N,j>=0;j--,i++)
    if(board[i][j]==1)
    return false;

return true;
}




bool NQutil(int col){

int i;

if(col>=N) return true;

        for(i=0;i<N;i++){
        if(isSafe(i,col)){
            board[i][col]=1;

            if(NQutil(col+1)==true)
                return true;
            board[i][col]=0;

                }

            }
        return false;
    }






void solve(){
int i,j;
for(i=0;i<N;i++)                   //Intialisation
    for(j=0;j<N;j++)
        board[i][j]=0;

if(NQutil(0))
    printboard();
else
    cout<<"Solution Doesnt exist!";
}


int main(){

cout<<"Enter N-Queens : ";
cin>>N;
solve();
return 0;
}
