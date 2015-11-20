#include<iostream>
#include<list>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int a[100005];
int dist[100005];
bool visited[100005];
vector<int> v[10];

void BFS(int sp,int len){
int i;

for(i=0;i<len;i++)
    {
     dist[i]=100000;
     visited[i]=false;
    }

bool mark[10];
for(i=0;i<10;i++)
    mark[i]=false;


dist[0] = 0;
visited[0] = true;

list<int> q;
q.push_back(0);

        while(!q.empty()){

            int s =q.front();
            q.pop_front();
            //cout<<"s";

            if(mark[a[s]]==false){

            for(int j=0;j!=v[a[s]].size();j++)
                {

                    int pos = v[a[s]][j];

                    if(dist[pos]>dist[s]+1&&visited[pos]==false)
                    {
                       // cout<<"IN THE LOOP ";
                      //  cout<<pos<<endl;
                        visited[pos]=true;
                        dist[pos]=dist[s]+1;
                        q.push_back(pos);

                    }
                }
            mark[a[s]]=true;
            }


            if(s+1<len&&visited[s+1]==false&&dist[s+1]>dist[s]+1)
            {
                visited[s+1]=true;
                dist[s+1]=dist[s]+1;
                q.push_back(s+1);
            }
            if(s>0&&dist[s-1]>dist[s]+1){
                dist[s-1]=dist[s]+1;
                visited[s-1]=true;
                q.push_back(s-1);
                }
            }

            //for(i=0;i<len;i++)
           // { cout<<dist[i]<<endl; }

return ;
}


int main(){
int i,j,n;

char  s[100005];
scanf("%s",&s);

int len=strlen(s);



for(i=0;i<len;i++){
    a[i] = s[i]-'0';
    v[a[i]].push_back(i);
    }

/*for(i=0;i<10;i++)
{   cout<<i<<" ";
    for(j=0;j!=v[i].size();j++)
        cout<<v[i][j]<<"->";
    cout<<endl;
}*/

BFS(0,len);
printf("%d",dist[len-1]);
return 0;
}
