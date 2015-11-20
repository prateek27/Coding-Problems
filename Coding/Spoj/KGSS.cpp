#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;

#define INT_MIN -222222
struct treeNode{
int firstMax;
int secondMax;
};

int arr[100005];
treeNode tree[400020];

void makeSegmentTree(int ss,int se,int si)
{
    if(ss==se)
    {
        tree[si].firstMax = arr[ss];
        tree[si].secondMax = INT_MIN;
        return ;
    }
    else{
    int mid = (ss+se)/2;
     makeSegmentTree(ss,mid,2*si+1);
     makeSegmentTree(mid+1,se,2*si+2);

     treeNode left= tree[2*si+1];
     treeNode right = tree[2*si+2];

    if(left.firstMax>right.firstMax)
    {tree[si].firstMax = left.firstMax;
     tree[si].secondMax = max(left.secondMax,right.firstMax);
    }
    else{
     tree[si].firstMax = right.firstMax;
     tree[si].secondMax = max(right.secondMax,left.firstMax);
      }
    }
}

treeNode MaxPairSumQuery(int ss,int se,int qs,int qe,int si){
if(qs<=ss&&qe>=se)
    {
        //<<"I returned "<<tree[si].firstMax<<endl;
        return tree[si];
    }
if(se<qs||ss>qe)
    return ((treeNode){INT_MIN,INT_MIN});

int mid = (ss+se)/2;

treeNode left = MaxPairSumQuery(ss,mid,qs,qe,2*si+1);
treeNode right = MaxPairSumQuery(mid+1,se,qs,qe,2*si+2);

treeNode temp;

    if(left.firstMax>right.firstMax)
    {temp.firstMax = left.firstMax;
     temp.secondMax = max(left.secondMax,right.firstMax);
    }
    else{
     temp.firstMax = right.firstMax;
     temp.secondMax = max(right.secondMax,left.firstMax);
    }
 return temp;
}

void update(int ss,int se,int idx,int pos,int val){
if(ss==se&&ss==pos){
    tree[idx]=((treeNode){val,INT_MIN});
    //<<"Updating..."<<endl;
    return ;
}
int mid = (ss+se)/2;
if(pos<=mid){
    update(ss,mid,2*idx+1,pos,val);
    }

else if(pos>mid)
    update(mid+1,se,2*idx+2,pos,val);

treeNode left = tree[2*idx+1];
treeNode right = tree[2*idx+2];

    if(left.firstMax>right.firstMax)
    {
     tree[idx].firstMax = left.firstMax;
     tree[idx].secondMax = max(left.secondMax,right.firstMax);
    }
    else{
     tree[idx].firstMax = right.firstMax;
     tree[idx].secondMax = max(right.secondMax,left.firstMax);
    }
}

int main(){
int n,q,i,l,r;
char ch;
cin>>n;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    makeSegmentTree(0,n-1,0);
       cin>>ch;
       scanf("%d",&q);
       while(q--){

         scanf(" %c%d%d",&ch,&l,&r);
        if ( ch == 'U' ) {
            update(0,n-1,0,l-1,r );
        }
        else {
            treeNode ans =MaxPairSumQuery(0,n-1,l - 1,r - 1,0);
            printf("%d\n", ans.firstMax+ans.secondMax);
        }
    }


return 0;
}
