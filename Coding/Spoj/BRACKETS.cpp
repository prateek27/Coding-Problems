#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 30005

struct treeNode{
int leftUnpaired;
int rightUnpaired;
};

char arr[MAX];
treeNode tree[4*MAX];

void makeSegmentTree(int si,int ss,int se){
if(ss==se){
    if(arr[ss]=='(')
        tree[si]=((treeNode){1,0});
    else
        tree[si]=((treeNode){0,1});
    return;
    }
    int mid=(ss+se)/2;
    makeSegmentTree(2*si+1,ss,mid);
    makeSegmentTree(2*si+2,mid+1,se);

    treeNode left = tree[2*si+1];
    treeNode right= tree[2*si+2];

    int pairings = min(left.leftUnpaired,right.rightUnpaired);
    tree[si].leftUnpaired = left.leftUnpaired - pairings + right.leftUnpaired;
    tree[si].rightUnpaired = right.rightUnpaired - pairings + left.rightUnpaired ;

}

void update(int idx,int ss,int se,int pos){
if(ss==se){
        if(tree[idx].leftUnpaired==1)
        {
            tree[idx].leftUnpaired=0;
            tree[idx].rightUnpaired=1;
        }
        else{
            tree[idx].leftUnpaired=1;
            tree[idx].rightUnpaired=0;
        }
}
else{
    int mid = (ss+se)/2;
    if(pos<=mid)
        update(2*idx+1,ss,mid,pos);
    else if(pos>mid)
        update(2*idx+2,mid+1,se,pos);

    treeNode left = tree[2*idx+1];
    treeNode right = tree[2*idx+2];

    int pairings = min(left.leftUnpaired,right.rightUnpaired);
    tree[idx].leftUnpaired = left.leftUnpaired - pairings + right.leftUnpaired;
    tree[idx].rightUnpaired = right.rightUnpaired - pairings + left.rightUnpaired ;
    }
}



int main(){
int cases=1,n,m,c;
while(1){
    if(cases==11)
        break;
    scanf("%d",&n);
    scanf("%s",&arr);
   // cout<<arr<<endl;
    makeSegmentTree(0,0,n-1);

    printf("Test %d:\n",cases);
    scanf("%d",&m);
    int query;

    while(m--){

        scanf("%d",&query);
        if(query==0){
            //cout<<tree[0].leftUnpaired<<" "<<tree[0].rightUnpaired<<endl;
            if(tree[0].leftUnpaired==0&&tree[0].rightUnpaired==0)
                printf("YES\n");
            else
                printf("NO\n");
            }
        else{
            update(0,0,n-1,query-1);
            }
    }
    cases++;
}
return 0;
}
