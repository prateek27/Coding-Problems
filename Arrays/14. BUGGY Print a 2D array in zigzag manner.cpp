#include<iostream>
using namespace std;


/* THIS PROGRAM IS INCOMPLETE */

svoid printZigZag(int **a,int n){
int i,j;
i=0; j=0;

bool up = true;

while(i!=n-1||j!=n-1){
    cout<<a[i][j]<<" ";
/*
    if(up==true&&i==0){
        up = false;
        j++;
        continue;
    }
    if(up==true&&i>0)
    {
        i++;
        j--;
        continue;
    }
    if(up==false&&j==0){
        up = true;
        i++;
        continue;
    }
    if(up==false&&j>0){

        i--;
        j++;
        continue;
    }

 }
*/
}



int main(){
int n;
cin>>n;
int **a = new int*[n];

for(int i=0;i<n;i++)
    a[i] = new int[n];

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
}
printZigZag(a,n);
return 0;
}
