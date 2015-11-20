#include<iostream>
using namespace std;

int bsearch(int a[],int low,int high,int item){
if(low>high)
        return -1;

while(low<=high){


        int mid=(low+high)/2;

        if(item==a[mid])
            return mid;
        else if(item>a[mid])
            bsearch(a,mid+1,high,item);
        else
            bsearch(a,low,mid-1,item);

}

}
int main(){
int a[20],n,key;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"Enter Item to be searched ";
cin>>key;

cout<<endl<<"Found at position "<<bsearch(a,0,n-1,key)+1;
return 0;
}
