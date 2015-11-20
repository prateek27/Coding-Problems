#include<iostream>
#include<cstdio>
using namespace std;

struct treeNode{
int maxFreq;
int leftFreq;
int rightFreq;
int leftIndex;
int rightIndex;
};

int a[100005];
treeNode tree[350000];


void makeSegmentTree(int idx,int ss,int se){

if(ss==se){
    tree[idx].maxFreq=1;
    tree[idx].rightFreq=1;
    tree[idx].leftFreq =1;
    tree[idx].leftIndex =ss;
    tree[idx].rightIndex=ss;
    return ;
    }

else{
    int mid =(ss+se)/2;
    makeSegmentTree(idx*2+1,ss,mid);
    makeSegmentTree(idx*2+2,mid+1,se);

    treeNode left = tree[idx*2+1];
    treeNode right = tree[idx*2+2];

    tree[idx].leftFreq = max( left.leftFreq,a[left.leftIndex]==a[right.leftIndex] ? left.maxFreq+right.leftFreq:0);
    tree[idx].rightFreq = max( right.rightFreq,a[right.rightIndex]==a[left.rightIndex] ? right.maxFreq+left.rightFreq:0);
    tree[idx].maxFreq = max( a[left.rightIndex]==a[right.leftIndex]?left.rightFreq+right.leftFreq:0,max(left.maxFreq,right.maxFreq));
    tree[idx].leftIndex = left.leftIndex;
    tree[idx].rightIndex = right.rightIndex;
    }
}

treeNode maxFreqQuery(int idx,int ss,int se,int qs,int qe){

if(ss>=qs&&se<=qe)
            {
                return tree[idx];
                }

        if(qs>se||qe<ss)
        return ((treeNode){0,0,0,-1,-1});

        int mid = (ss+se)/2;

        treeNode left = maxFreqQuery(2*idx+1,ss,mid,qs,qe);
        treeNode right = maxFreqQuery(2*idx+2,mid+1,se,qs,qe);
        treeNode temp;


    temp.leftFreq = max( left.leftFreq,a[left.leftIndex]==a[right.leftIndex] ? left.maxFreq+right.leftFreq:0);
    temp.rightFreq = max( right.rightFreq,a[right.rightIndex]==a[left.rightIndex] ? right.maxFreq+left.rightFreq:0);
    temp.maxFreq = max( a[left.rightIndex]==a[right.leftIndex]?left.rightFreq+right.leftFreq:0,max(left.maxFreq,right.maxFreq));
    temp.leftIndex = left.leftIndex;
    temp.rightIndex = right.rightIndex;
        return temp;
}

int main(){
int n,q,i,l,r,zero;

while(1){

scanf("%d",&n);

if(n==0)
    break;

scanf("%d",&q);

for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    makeSegmentTree(0,0,n-1);

    while(q--){
    scanf("%d%d",&l,&r);
    printf("%d\n",maxFreqQuery(0,0,n-1,l-1,r-1).maxFreq);
    }
}
return 0;
}
