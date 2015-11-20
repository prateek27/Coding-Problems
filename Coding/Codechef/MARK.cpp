#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MAX 110
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define MOD 1000000007
#define printl(n) ("%lld\n",n);
#define ll long long

int fa[105],fb[105],fc[105],fd[105],fe[105];
int ca,cb,cc,cd,ce;

int main(){
int n,i,mark;
char s;
si(n);
CLEAR(fa);
CLEAR(fb);
CLEAR(fc);
CLEAR(fd);
CLEAR(fe);
FOR(i,0,n){
scanf(" %c%d",&s,&mark);

switch(s){
    case 'A': ca++ ;fa[mark]++;break;
    case 'B': cb++ ;fb[mark]++;break;
    case 'C': cc++ ;fc[mark]++;break;
    case 'D': cd++ ;fd[mark]++;break;
    case 'E': ce++ ;fe[mark]++;break;
    }
}
bool a=false;
FOR(i,0,101){
    if(fa[i]>ca/10)
        {printf("%d ",i);
         a=true;
        }
}
a==true?printf("\n"):printf("Nothing Unusual\n");


bool b=false;
FOR(i,0,101){
    if(fb[i]>cb/10)
        {printf("%d ",i);
         b=true;
        }
}
b==true?printf("\n"):printf("Nothing Unusual\n");


bool c=false;
FOR(i,0,101){
    if(fc[i]>cc/10)
        {printf("%d ",i);
         c=true;
        }
}
c==true?printf("\n"):printf("Nothing Unusual\n");


bool d=false;
FOR(i,0,101){
    if(fd[i]>cd/10)
        {printf("%d ",i);
         d=true;
        }
}
d==true?printf("\n"):printf("Nothing Unusual\n");


bool e=false;
FOR(i,0,101){
    if(fe[i]>ce/10)
        {printf("%d ",i);
         e=true;
        }
}
e==true?printf("\n"):printf("Nothing Unusual\n");

return 0;
}
