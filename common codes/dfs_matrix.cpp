// http://codeforces.com/contest/540/problem/C
#include<stdio.h>
char s[502][502];
int r,c,x,y,a[]={1,0,-1,0},b[]={0,1,0,-1};
int meth(int r,int c)
{
    if(r==x && c==y && s[r][c]=='X')
        return 1;
    if(s[r][c]!='.')
        return 0;
    s[r][c]='X';
    int i;
    for(i=0;i<4;++i)
        if(meth(r+a[i],c+b[i]))
            return 1;
    return 0;
}
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%s",1+s[i]);
    scanf("%d%d%d%d",&r,&c,&x,&y);
    s[r][c]='.';
    if(meth(r,c))
        printf("YES");
    else
        printf("NO");
    return 0;
}
