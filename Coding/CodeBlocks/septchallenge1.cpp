#include<iostream>
using namespace std;



int main(){
int t,r,c,i,j,monster=0;
char a[50][50]; // Enter varialbe is used to store the enter !
cin>>t;

while(t--){
cin>>r>>c;

                       //Scanning Unit
for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        cin>>a[i][j];
    }
    }


                               //Counting Unit
for(i=2;i<r-2;i++){
       for(j=2;j<c-2;j++){

if((a[i][j]=='^')&&(a[i][j-1]=='^')&&(a[i][j-2]=='^')&&(a[i-1][j]=='^')&&(a[i-2][j]=='^')&&(a[i+1][j]=='^')&&(a[i+2][j]=='^')&&(a[i][j+1]=='^')&&(a[i][j+2]=='^'))
          {
            monster++;}
        }}

cout<<monster<<endl;
monster=0;
}
return 0;
}
