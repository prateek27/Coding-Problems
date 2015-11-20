#include<iostream>
using namespace std;

#define R 6
#define C 5
int min(int a, int b, int c)
{
  int m = a;
  if (m > b)
    m = b;
  if (m > c)
    m = c;
  return m;
}
void printMaxSubSquare(int M[R][C])
{
    int i,j;
    int S[R][C];


    for(i=0;i<R;i++) S[i][0]=M[i][0];
    for(i=0;i<C;i++) S[0][i]=M[0][i];

    for(i=1;i<R;i++)
    {
        for(j=1;j<C;j++)
            if(M[i][j]==1)
            S[i][j]=min(S[i-1][j-1],S[i][j-1],S[i-1][j])+1;
            else
                S[i][j]=0;
    }
    int maxi=0;
    int maxs=0;
    int maxj=0;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++)
        {

            if(S[i][j]>maxs)
            {
                maxs=S[i][j];
                maxi=i;
                maxj=j;
            }
        }

    }

    for(i=maxi-maxs+1;i<=maxi;i++)
    {
        for(j=maxj-maxs+1;j<=maxj;j++)
            cout<<M[i][j]<<"  ";
    cout<<endl;
    }

    cout<<"Size of Maximum submatrix is "<<maxs<<endl;
}

int main()
{

    int M[R][C]={{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    printMaxSubSquare(M);

return 0;
}
