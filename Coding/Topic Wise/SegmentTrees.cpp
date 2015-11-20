#include<iostream>
#include<cstdio>
using namespace std;

int a[5005];
int st[5005];

int getMid(int s,int e)
{
    return s+(e-s)/2;
}
//Get Sum Utility
int getSumUtil(int *st,int ss,int se,int qs,int qe,int index)
{
    if(qs<=ss&&qe>=se) //This ranges is included
        return st[index];

if(qs>se||qe<ss)  //Out of range
    return 0;
int mid=getMid(ss,se);
return getSumUtil(st,ss,mid,qs,qe,2*index+1)+getSumUtil(st,mid+1,se,qs,qe,2*index+2);
}
//Update value

void updateValueUtil(int *st,int ss,int se,int i,int diff,int index){
if(i<ss||i>se)
    return;

st[index]=st[index]+diff; //jis node pe aaya
if(se!=ss)
    {
        int mid=getMid(ss,se);
        updateValueUtil(st,ss,mid,i,diff,2*index+1);
        updateValueUtil(st,mid+1,se,i,diff,2*index+2);
    }
}

void updateValue(int arr[],int *st,int n,int i,int new_val){

int diff=new_val-arr[i];
arr[i]=new_val;
updateValueUtil(st,0,n-1,i,diff,0);
}

int getSum(int *st,int n,int qs,int qe)
{
    return getSumUtil(st,0,n-1,qs,qe,0);
}


int constructSTUtil(int arr[],int ss,int se,int *st,int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int main(){



}
