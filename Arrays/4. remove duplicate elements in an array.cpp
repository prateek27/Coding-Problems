#include<iostream>
#include<map>
using namespace std;


void removeDuplicates(int* a,int *b,int n){
map<int,bool> pmap ;
int j=0;
for(int i=0;i<n;i++){
 if(pmap.count(a[i])==0)
    {
    b[j++]=a[i];
    pmap[a[i]]=true;}
    }
int i;
for(i=0;i<j;i++)
    cout<<b[i];
}


int main(){
int in[]= {2,1,7,2,2,3,7,7,8};
int out[100];
int n = sizeof(in)/sizeof(int);
removeDuplicates(in,out,n);
return 0;
}
