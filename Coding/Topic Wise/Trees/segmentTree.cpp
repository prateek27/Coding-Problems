#include<iostream>
using namespace std;





//--------------------------------------Get Mid
int getMid(int i,int j){
return i + (j-i)/2 ;  //mid of two elements.
}


//---------------------------------------------constructUTIL
int constructSTUtil(int arr[],int i,int j,int *st,int n)
{
    if(i==j)
    {
        st[n]=arr[i];
    }
    int mid=getMid(i,j);
    st[n]=constructSTUtil(arr,i,mid,st,i*2+1)+constructSTUtil(arr,mid+1,j,st,si*2+2);
    return si[i];
}

int *constructST(int arr[],int n)
{
    int x= (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,x) - 1;
    int *st = new int[max_size];

    constructSTUtil(arr,0,n-1,0);  //Fill the allocated memory with 0

    return st;
}

//--------------------Main !
int main(){
int a[]={1,3,5,7,9,11};
int n=sizeof(arr)/sizeof(arr[0]);

int *st=constructST(arr,n);


return 0;
}
