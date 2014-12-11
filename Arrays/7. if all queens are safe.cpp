#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct node{
int x;
int y;
};

bool isSafe(int board[][4],int n)
{
  vector<node> v;
  int i,j;
 struct node n1;
  // Store the queen Positions
 v.clear();
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(board[i][j]==1){

             n1.x = i;
             n1.y = j;

            v.push_back(n1);
            cout<<n1.x<<" "<<n1.y<<endl;
    }
  }
  }

  for(i=0;i<v.size();i++){
    for(j=i+1;j<v.size();j++){
        int x1 = v[i].x;
        int y1 = v[i].y;
        int x2 = v[j].x;
        int y2 = v[j].y;
        // cout<<x1<<" "<<y1<<":"<<x2<<" "<<y2<<endl;
        if(x1==x2)
            return false;
        if(y1==y2)
            return false;
        if(abs(x2-x1)==abs(y2-y1))
            return false;
    }

  }

return true;
}



int main()
{
int board[][4] = {{1,0,0,0},
              {0,0,0,0},
              {0,0,0,0},
              {0,0,1,0}};
int i,j;
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        cout<<board[i][j]<<" ";
        }
    cout<<endl;
    }

if(isSafe(board,4))
    cout<<"Queens Safe hain ! ";
else
    cout<<"Queens ko khatra hai !";

return 0;
}
