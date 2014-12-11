#include<iostream>
using namespace std;


//Time Complexity in O(m+n) m: Rows , N: Columns
void  matrixSearch(int a[1000][1000],int key,int r,int c){

int i=0,j=c-1;
while(i<r&&c>=0){
    if(a[i][j]==key){ cout<<"Found! " ; return ;}
    else if(a[i][j]>key)
    { j--; }
    else
    { i++;}

}
cout<<"NOT FOUND !";
return;
}


int main(){

int a[1000][1000] ={{1,2,3},
             {4,5,6},
             {7,8,9}};
matrixSearch(a,1,3,3);

return 0;
}

