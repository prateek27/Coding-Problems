#include<stdio.h>


int main(){
int t,r,c,i,j,monster=0;
char a[50][50];char enter; // Enter varialbe is used to store the enter !
scanf("%d",&t);

while(t--){
scanf("%d%d%c",&r,&c,&enter);

                       //Scanning Unit
for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        scanf("%c",&a[i][j]);
    } fflush(stdin);
    }


                               //Counting Unit
for(i=2;i<r-2;i++){
       for(j=2;j<c-2;j++){

if((a[i][j]=='^')&&(a[i][j-1]=='^')&&(a[i][j-2]=='^')&&(a[i-1][j]=='^')&&(a[i-2][j]=='^')&&(a[i+1][j]=='^')&&(a[i+2][j]=='^')&&(a[i][j+1]=='^')&&(a[i][j+2]=='^'))
          {
              monster++;}
        }}

printf("%d\n",monster);
monster=0;

}
return 0;
}
