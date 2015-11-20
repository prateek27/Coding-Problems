#include<iostream>
using namespace std;


int main(){
int t,r,c,m,i,j,monster=0,left=0;
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
for(i=0;i<r;i++){
       for(j=0;j<c;j++){

       for(m=j;m>=0;m--){            //LEFT
        if(a[i][m]=='#') break;
        left++;
       }
        cout<<endl<<"TO the left of "<<a[i][j]<<" are "<<left-1;
        left=0;

        }}


}
return 0;
}
