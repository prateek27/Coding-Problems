#include<iostream>
#include<vector>

using namespace std;

// Approach 1 : Time O( N ^ 3) , Space O( N^2 )
void makeZeroes(int a[100][100],int n)
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

        for(j=0;j<n;j++)
            a[x][j] = 0;

        for(j=0;j<n;j++)
            a[j][y] = 0;

    }

v.clear();
return ;
}

// Approach 2 : Time O(n^2) , Space O(1)
//Convert all 1s to -1s in the row/col when 0 is found.
//Atlast last convert all -1s to zeroes and retains 1s.

void makeZeroes2(int a[100][100],int n){

    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            if(a[i][j]==0)
            a[i][j] = -1;

        }
    }



}

void print(int a[100][100],int n){



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<a[i][j];
        }
        cout<<endl;
    }
cout<<endl;
}

int main(){

int a[][100] = { {1,0,0,1,1},{1,1,1,1,1},{0,0,0,1,1},{1,1,0,1,1},{1,1,0,1,1}};
cout<<"BEFORE"<<endl;
print(a,5);
makeZeroes(a,5);
cout<<"AFTER"<<endl;
print(a,5);
return 0;
}
