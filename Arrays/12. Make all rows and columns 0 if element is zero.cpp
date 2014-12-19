#include<iostream>
#include<vector>

using namespace std;


void makeZeroes(int a[][100],int n)
{

    vector<pair<int,int> > v ;
    int i,j;

    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            if(a[i][j]==0)
                    v.push_back(make_pair(i,j));

        }
    }
    for(i=0;i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;

        for(i=0;i<n;i++)
            a[x][i] = 0;

        for(j=0;j<n;j++)
            a[j][y] = 0;

    }

v.clear();
return ;
}

void print(int a[100][100],int n){



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<a[i][j]<<"Hey ";
        }
        cout<<endl;
    }
}

int main(){

int a[][100] = { {1,0,0,1,1},{1,0,1,1,1},{0,0,0,1,1},{1,1,0,1,1},{1,1,0,1,1}};
makeZeroes(a,5);
print(a,5);
return 0;
}
