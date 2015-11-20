#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int bsearch(int a[],int low,int high,int key){

while(low<=high){
    int mid=(low+high)/2;

    if(key==a[mid])
        return 1;
    else if(key>a[mid])
        low=mid+1;
    else if(key<a[mid])
        high=mid-1;

    }

return 0;
}



main(){
int t,i,key,n,m,count=0;
scanf("%d",&t);
while(t--){
    scanf("%d%d",&n,&m);
    int a[n];
    for(i=0;i<n;i++){
    scanf("%d",&a[i]); }
    std::sort(a,a+n);
    for(i=0;i<n;i++)
    {
     key=m-a[i];
     if(bsearch(a,i+1,n-1,key))
        count++;
    }
    printf("%d\n",count);
    count=0;
}




return 0;
}
