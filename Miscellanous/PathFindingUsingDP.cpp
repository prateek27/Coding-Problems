#include<iostream>
#include<vector>
#include<map>
using namespace std;


class doubleInt{

public:
int x;
int y;

    doubleInt(int x,int y){
        this->x = x;
        this->y = y;
    }
};
//int calls=0;
map< pair<int,int>,bool> hashmap;

bool findPath(int path[10][10],int x,int y,vector<doubleInt> &v){

if(x==0&&y==0){
    return true;
    }

    pair<int,int> p(x,y);

    if(hashmap.count(p)>0){
        return hashmap[p];
    }
    //calls++;

    bool success = false;
    //Try left
    if(x>=1 && path[x][y]!=1){
        success = findPath(path,x-1,y,v);
    }

    if(!success && y>=1&& path[x][y]!=1){
        success = findPath(path,x,y-1,v);
    }

    hashmap[p] = success;

    if(success){
        v.push_back(doubleInt(x,y));
    }

return success;
}

int main(){
// 1 means path is blocked.
int path[10][10] = {{0,1,1,1,0,0,0} ,
                    {0,0,0,0,0,0,0},
                    {1,0,1,0,0,0,0},
                    {1,0,0,0,0,0,0},
                   };

vector<doubleInt> v;
findPath(path,7,7,v);

for(int i=0;i<v.size();i++){
    cout<<v[i].x<<","<<v[i].y<<endl;
}
//cout<<calls;
return 0;
}
