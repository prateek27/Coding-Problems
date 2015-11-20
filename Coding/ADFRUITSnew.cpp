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

int lcs(int la,int lb){
int i,j;
for(i=0;i<=lb;i++)
{
    for(j=0;j<=la;j++)
    {
        if(i==0||j==0)
            {
             dp[i][j]=0;
             if(i==0) dir[i][j]=1;
             if(j==0) dir[i][j]=3;
            }

        else{
            if(a[j-1]==b[i-1]) //Diag
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
            }
        }
    }
}
return dp[la][lb];
}

void printlcs(int la,int lb){
int i=la,j=lb;

/*for(i=0;i<=lb;i++)
{
    for(j=0;j<=la;j++)
       // cout<<dp[i][j]<<"-"<<dir[i][j]<<"  ";
    //cout<<endl;
}*/
i=lb;j=la;
int k=0;
while(1)
{
    if(i==0&&j==0) break;

    if(dir[i][j]==2)
       {
         res[k++]=b[i-1];
         i--;
         j--;
       }
    else if(dir[i][j]==1)
       {
         res[k++]=a[j-1];
            j--;
       }
    else{
        res[k++]=b[i-1];
        i--;
    }
}

}





int main(){
while(scanf("%s%s",&a,&b)!=EOF)
{
   int l1=strlen(a);
   int l2=strlen(b);
   int len=lcs(l1,l2);
   printlcs(l1,l2);

    for(int l=l1+l2-len-1;l>=0;l--)
    printf("%c",res[l]);
    printf("\n");
  }

return 0;
}

