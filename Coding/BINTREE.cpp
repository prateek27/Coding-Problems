#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define gc getchar_unlocked
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}


inline void fastwrite(int a){
register char c;
char snum[20];
int i=0;
do{
snum[i++]=a%10+48;
a=a/10;
}while(a!=0);
i=i-1;
while(i>=0)
putchar_unlocked(snum[i--]);
putchar_unlocked('\n');
}


vector<int> vi,vj;

int main(){
int t;
int i,j,x,y;
t=fcin();

while(t--){
    x=fcin();
    y=fcin();
    i=x,j=y;
    while(i>0)
    {
        vi.push_back(i);
        i>>=1;
    }
    while(j>0)
    {
        vj.push_back(j);
        j>>=1;
    }
    int n;
    //sort(vi,);
        int parent=-1;

        sort(vj.begin(),vj.end());
        for(i=0;i<vi.size();i++)
       {
          if(binary_search(vj.begin(),vj.end(),vi[i]))
          {

              parent=vi[i];
            // cout<<"Parent"<<parent<<endl;
              break;
          }
        }

        int ans = floor(log2(x)) + floor(log2(y))-2*floor(log2(parent));

        fastwrite(ans);
        vi.clear();
        vj.clear();
}

return 0;
}
