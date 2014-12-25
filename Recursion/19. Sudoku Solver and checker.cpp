#include<iostream>
#include<cmath>
using namespace std;

void print(int **a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool canPlace(int**puzzle,int x,int y,int no,int n){

int i;
for(i=0;i<n;i++)
{
//Same Row
if(puzzle[x][i]== no&&i!=y)
    return false;
}

//Same Column
for(i=0;i<n;i++){
    if(puzzle[i][y]==no&&i!=x)
        { return false; }
}
int rn = sqrt(n);

int startX = (x/rn)*rn;
int startY = (y/rn)*rn;

//Same SubGrid
for(int i=startX;i<startX+rn;i++){
    for(int j=startY;j<startY+rn;j++){
        {
            if(puzzle[i][j]==no&&i!=x&&j!=y)
                {
                    return false;
                }
        }
    }
}

return true;
}



bool sudokuHelper(int **puzzle,bool **marked,int row,int col,int n){


    if(row==n){
    return true;
    }

    if(col==n)
    {
    return sudokuHelper(puzzle,marked,row+1,0,n);
    }

    int  possible ;

    if(marked[row][col]==false) {

            for(possible = 1;possible<=n;possible++){
                if(canPlace(puzzle,row,col,possible,n)){
                    puzzle[row][col] = possible;

                    if(sudokuHelper(puzzle,marked,row,col+1,n)) {
                        return true;
                    }
                    puzzle[row][col] = 0;
                }
            }
            return false;

    }
    //Else skip the current position as it is fixed already !
    else{
        return sudokuHelper(puzzle,marked,row,col+1,n);
    }

}


void sudokuSolver(int **puzzle,int n){
bool **marked = new bool*[n];
int i,j;

for(i=0;i<n;i++)
    marked[i] = new bool[n];

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(puzzle[i][j]!=0)
        {
            marked[i][j]=1;
        }
    }
}
/*
for(i=0;i<n;i++){
    for(j=0;j<n;j++)
    {
        cout<<marked[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;*/
sudokuHelper(puzzle,marked,0,0,n);

}

//--------------------------------------Sudoku Checker




bool isValid(int **puzzle,int n){


for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(canPlace(puzzle,i,j,puzzle[i][j],n)==false)
            return false;
    }
return true;
}

}


int main(){
int n,i,j;
n = 9;
int **puzzle = new int*[n];

for(i=0;i<n;i++)
    puzzle[i] = new int[n];


int mat[100][100] = {{8,0,0,7,5,0,0,4},
        {0,0,0,1,0,0,0,0,0},
        {5,1,0,4,0,6,0,0,7},
        {0,0,4,0,0,0,0,5,0},
        {1,0,5,0,0,0,7,0,8},
        {0,2,0,0,0,0,4,0,0},
        {0,0,0,9,0,2,0,6,1},
        {0,0,0,0,0,3,0,0,0},
        {0,0,0,0,6,1,0,0,5}};

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        puzzle[i][j]=mat[i][j];

print(puzzle,n);
cout<<endl;
sudokuSolver(puzzle,n);
print(puzzle,n);
cout<<"Let's check the validity :";
if(isValid(puzzle,n))
    cout<<" Puzzle Solved ,Well Done !"<<endl;
else
    cout<<" Incorrect Solution :( "<<endl;
return 0;
}
