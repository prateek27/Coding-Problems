#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define  vii vector< pair<int,int > >
vii a[100005],b[100005];
int ans[100005];
bool myfunction( pair<int,int> a,pair<int,int> b )
{
return a.first<b.first;
}
int main(){

int n,m,p,i;
scanf("%d%d%d",&n,&m,&p);

for(i=1;i<=p;i++)
{
    int x,y;
    scanf("%d%d",&x,&y);
    pair<int,int> p = make_pair(y,1);
    a[x].push_back(p);
}

vector< pair<int,int > > :: iterator j,temp;

for(i=1;i<=n;i++)
{
sort( a[i].begin(),a[i].end(),myfunction );
}

/*for(i=1;i<=n;i++)
{
cout<<"Row "<<i<<"  ";
    for(j=a[i].begin();j!=a[i].end();j++)
        { cout<<(*j).first<<","<<(*j).second<<" ";}
cout<<endl;
}*/

for(i=1;i<=n;i++)
{
    int last = -1;
    for(j=a[i].begin();j!=a[i].end();j++)
        {
        if((*j).first!=last)
            {
                b[i].push_back(*j);
                last=(*j).first;
                temp = j;
            }
        else{
            b[i].back().second++;
            }
        };
}
/*
for(i=1;i<=n;i++)
{
cout<<"Row "<<i<<"  ";
    for(j=b[i].begin();j!=b[i].end();j++)
        { cout<<(*j).first<<","<<(*j).second<<" ";}
cout<<endl;
}
*/

for(i=1;i<=n;i++)
{

    if(b[i].size()>1)
    {
    j=b[i].begin();
     int ct1,ct2;
     ct1=ct2=0;
    bool valid=true;
    int index = (*j).first;
    int val = (*j).second;
    if(index==1)
    {
        ct1=val;

    }
    int index2,val2;

    for(j=b[i].begin();j!=b[i].end();j++)
        {
            if(j!=b[i].begin())
            {

            index2=(*j).first;
            val2=(*j).second;
            if(index2==m)
            {
                ct2=val2;
            }
            if(index2-index==1)
                {
                    if((val-val2>1))
                    {

                    valid=false;
                    break;
                    }
                    index=index2;
                val=val2;
                }
               else if(index2-index>1)
               {
                    if(val>=2)
                    {
                        valid=false;
                        break;
                    }
                    index=index2;
                val=val2;
               }

            }
        }
        if(index<m && (val>=2))
        {
            valid=false;
        }
      if(valid==true)
      {
          ans[i]=m-1-ct1+ct2;
      }
      else
        ans[i]=-1;


    }
    else if(b[i].size()==1)
    {
        j = b[i].begin();
        int index = (*j).first;
    int val = (*j).second;
    int ct1,ct2;ct1=ct2=0;
    if(index==1)
        ct1=val;
    if(index==m)
        ct2=val;
    if(val>=2 && index<m)
    {
        ans[i]=-1;
    }
    else
        ans[i]=m-1-ct1+ct2;
    }
else{
    ans[i]=m-1;
    }

}
for(i=1;i<=n;i++)
{
  printf("%d\n",ans[i]);
}
return 0;
}




