#include<iostream>
#include<cstdio>
#include<algorithm>
int a[2005];
using namespace std;

bool lowFunc(int no,int key){ return no>=key; }
int lowerBound(int low,int high,int key)
{
int last=high;
int bestSoFar=0;
while(low<=high){
        int x=(low+high)/2;
        if(lowFunc(a[x],key))
        {
            bestSoFar=x;
            high=x-1;
        }
        else
            low=x+1;
        }
//cout<<"Lower Bound"<<bestSoFar<<endl;
if(bestSoFar)
    return last-bestSoFar+1;
else
    return 0;
}

int calcNotTriangle(int n)
{       int i,j,ans=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                    int twoSum=a[i]+a[j];
                    ans+=lowerBound(j,n-1,twoSum+1);
            }

        }

return ans;
}

int main(){
int n,i;
while(scanf("%d",&n),n!=0)
{
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        sort(a,a+n);
        printf("%d\n",calcNotTriangle(n));
}

}
