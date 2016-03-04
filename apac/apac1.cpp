#include<bits/stdc++.h>
using namespace std;

/*
int findRegions(int a[105][105],int r,int c){
int region[100][100]={0};

int cnt=0;
int i;

//Leftwise checking for first row
for(i=0;i<c;i++){
    if(a[0][i]==1&&cnt==0){
        cnt++;
        region[0][i]=cnt;
    }

    else if(i>0&&a[0][i-1]==1&&a[0][i]==1){
        region[0][i] = region[0][i-1];
    }
    else if(i>0&&a[0][i-1]==0&&a[0][i]==1){
        cnt++;
        region[0][i] = cnt;
    }
}

//Top Bottom checking for first col
for(i=0;i<r;i++){
    if(a[i][0]==1&&cnt){
        cnt++;
        region[i][0]=cnt;
    }
    else if(i>0&&a[i-1][0]==1&&a[i][0]==1){
        region[i][0] = region[i-1][0];
    }
    else if(i>0&&a[i-1][0]==0 &&a[i][0]==1){
        cnt++;
        region[i][0] = cnt;
    }
}





for(int i=1;i<r;i++){
    for(int j=1;j<c;j++){
        if(a[i][j]==1){

            if(a[i][j-1]==1&&a[i-1][j]==1){

                region[i][j] = min(region[i][j-1],region[i-1][j]);

                if(cnt==max(region[i][j-1],region[i-1][j])){
                    cnt--;
                }

                //Update the neighbours too.
                if(region[i][j-1] > region[i-1][j]){
                    //Move left.
                    int k=j-1;
                     while(k>=0&&a[i][k]==1){
                        region[i][k] = region[i][j];
                        k--;
                     }

                }

                 //Update the neighbours too.
                else if(region[i][j-1] < region[i-1][j]){
                    //Move Up.
                    int k=i-1;
                     while(k>=0&&a[k][j]==1){
                        region[k][j] = region[i][j];
                        k--;
                     }

                cnt--;
                }

            }
            else if(a[i][j-1]==1&&a[i-1][j]==0){
                region[i][j] = region[i][j-1];
            }
            else if(a[i][j-1]==0&&a[i-1][j]==1){
                region[i][j]= region[i-1][j];
            }
            else{
                //Both top and left are 0.
                cnt++;
                region[i][j] = cnt;

            }


        }

    }
}
cout<<endl;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
        {cout<<region[i][j]<<" ";}
        cout<<endl;
}
return cnt;
}
*/
bool inBounds(int x,int y,int r,int c){
if(x>=0&&y>=0&&x<r&&y<c){
    return true;
}
return false;
}
void  dfsVisit(int x,int y,int visited[105][105],int a[105][105],int r,int c){

visited[x][y]=1;

if(inBounds(x+1,y,r,c)&&visited[x+1][y]==0&&a[x+1][y]==1){
        dfsVisit(x+1,y,visited,a,r,c);
    }
if(inBounds(x,y-1,r,c)&&visited[x][y-1]==0&&a[x][y-1]==1){
        dfsVisit(x,y-1,visited,a,r,c);
    }
if(inBounds(x-1,y,r,c)&&visited[x-1][y]==0&&a[x-1][y]==1){
        dfsVisit(x-1,y,visited,a,r,c);
    }
if(inBounds(x,y+1,r,c)&&visited[x][y+1]==0&&a[x][y+1]==1){
        dfsVisit(x,y+1,visited,a,r,c);
    }
return;
}

int findCount(int a[105][105],int r,int c){
int visited[105][105]={0};

vector<pair<int,int> > v;

for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(a[i][j]==1){
            v.push_back(make_pair(i,j) );
        }
    }
}

int cnt=0;

for(int i=0;i<v.size();i++){
    int x =v[i].first;
    int y = v[i].second;

    if(visited[x][y]==0){
        dfsVisit(x,y,visited,a,r,c);
        cnt++;
        }
    }

return cnt;
}



int main(){
int t;

cin>>t;
int r,c;
char ch;

int a[105][105]={0};

while(t--){
cin>>r>>c;
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        scanf("%1d",&a[i][j]);
    }
}
int nop;

cin>>nop;
char op;

    while(nop--){
        cin>>op;
        if(op=='Q'){
            //Query for result
            cout<<"Case #1:"<<findCount(a,r,c)<<endl;

        }
        else if(op=='M'){
            //Update the array
            int x,y,val;
            cin>>x>>y>>val;
            a[x][y]=val;
        }

    }

}
return 0;
}
