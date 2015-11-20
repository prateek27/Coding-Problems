#include<iostream>
using namespace std;

#define FALSE 0
#define TRUE 1

try
check
void drawboard();

void main(){
int board[8][8];

for(i=0;i<8;i++){
    for(j=0;j<8;j++){
        a[i][j]=FALSE;
       }
    }
 if(try(0)==TRUE)
    drawboard();

}

int try(int n){
int i;
for(i=0;i<8;i++){

    board[n][i]=TRUE;

    if(n==7&&check()==TRUE)
        return(TRUE);

    if(n<=7&&check()==TRUE&&try(n+1)==TRUE)
        return(TRUE);
    board[n][i]=FALSE;             //BACKTRACK FROM HERE .
}
return FALSE;
}





