#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;




char a[105],b[105];
char res[205];

int dp[105][105];
int dir[105][105];
int seq[105][105];

//left 1
//diagup 2
//up 3

void lcs(int la,int lb){
int i,j;
for(i=0;i<=la;i++)
{
    for(j=0;j<=lb;j++)
    {
        if(i==0||j==0)
            {
             dp[i][j]=0;
             if(i==0) dir[i][j]=1;
             if(j==0) dir[i][j]=3;
            }

        else{
            if(a[i-1]==b[j-1]) //Diag
                {
                dp[i][j]=dp[i-1][j-1]+1;
                dir[i][j]=2;
                }
            else{
            if(dp[i-1][j]>=dp[i][j-1])  //Up
               { dp[i][j]=dp[i-1][j];
                 dir[i][j]=3;
               }
            else{                 //Left
                dp[i][j]=dp[i][j-1];
                dir[i][j]=1;
                }
            }}}}

}

void printlcs(int la,int lb){
int i=la,j=lb;
int k=0;
for(i=0;i<=la;i++)
{
    for(j=0;j<=lb;j++)
        cout<<dp[i][j]<<"-"<<dir[i][j]<<"  ";
    cout<<endl;
}
i=la;j=lb;
while(1)
{
    if(i==0||j==0) break;
    if(i<0) break;
    if(j<0) break;

    if(dir[i][j]==2)
    {
    cout<<" Diag"<<endl;
   //printf("%c",a[i-1]);
    res[k++]=a[i-1];
    i--;
    j--;
    }

    if(dir[i][j]==1)
    {
       cout<<"UP"<<endl;
       // printf("%c",b[j-1]);
       // s.push(b[j-1]);
        res[k++]=b[j-1];
        j--;
    }
    else{
        cout<<"left "<<endl;
        //printf("%c",a[i-1]);
       // s.push(a[i-1]);
        res[k++]=a[i-1];
        i--;
        }
    }
}





int main(){
while(scanf("%s%s",&b,&a)!=EOF)
{
   int l1=strlen(a);
   int l2=strlen(b);
   lcs(l1,l2);
   printlcs(l2,l1);
    for(int l=strlen(res)-1;l>=0;l--)
    printf("%c",res[l]);
    printf("\n");
}
return 0;
}
