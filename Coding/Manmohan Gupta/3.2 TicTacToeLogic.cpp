#include<iostream>
#include<math.h>
using namespace std;


int check(char a[10][10],int n){
    int i,j,numX=0,numO=0,num=0;


    for(i=0;i<n;i++){          //COLS
        for(j=0;j<n;j++){
            if(a[i][j]=='X') numX++;
            if(a[i][j]=='O') numO++;
            if(a[i][j]=='-') num++;


        }


        if(numX==n) return 2;
        if(numO==n) return 1;

        numX=0;numO=0;
        }

        for(j=0;j<n;j++){          //ROWS
        for(i=0;i<n;i++){
            if(a[i][j]=='X') numX++;
            if(a[i][j]=='O') numO++;
            if(a[i][j]=='-') num++;


        }

        if(numX==n) return 2;
        if(numO==n) return 1;

          numX=0;numO=0;
        }

        for(i=0;i<n;i++){
            if(a[i][i]=='O') numO++;
            if(a[i][i]=='X') numX++;
            if(a[i][i]=='-') num++;
            }
        if(numX==n) return 2;
        if(numO==n) return 1;

        numX=0;numO=0;

        for(i=0;i<n;i++){
            if(a[i][n-i-1]=='O') numO++;
            if(a[i][n-i-1]=='X') numX++;
            if(a[i][n-i-1]=='-') num++;
            }
        if(numX==n) return 2;
        if(numO==n) return 1;

        if(num) return 3;

        numX=0;numO=0;

return 0;
}



int main(){
char a[10][10];int n,i,j;
cout<<"Enter the size of Tic Tac Tog game : ";
cin>>n;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        cin>>a[i][j];
    }
}
int x=check(a,n);
switch(x){
case 0: cout<<endl<<"Dead Lock . Play a new Game ";break;
case 1: cout<<endl<<"O wins ";break;
case 2: cout<<endl<<" X wins ";break;
case 3: cout<<endl<<"Keep Playing "; break;
}

return 0;
}
