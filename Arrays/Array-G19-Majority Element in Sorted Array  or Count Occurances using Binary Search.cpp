#include<iostream>
using namespace std;


int getLowerBound(int *a,int low,int high,int key){
int ans=-1;
while(low<=high){
    int mid = (low+high)/2;

    if(a[mid]>key){
        high = mid-1;

    }
    else if(a[mid]<key){
        low = mid + 1;
    }
    else{
        ans = mid;
        high = mid-1;
    }
}

return ans;
}

int getUpperBound(int *a,int low,int high,int key){
int ans=-1;
while(low<=high){
    int mid = (low+high)/2;
    if(a[mid]>key){
        high = mid-1;

    }
    else if(a[mid]<key){
        low=mid+1;
    }
    else{
        ans = mid;
        low = mid+1;
    }
}
return ans;
}


int countOccurances(int *a,int n,int key){
int left_index = getLowerBound(a,0,n-1,key);
//cout<<left_index<<endl;
int right_index = getUpperBound(a,0,n-1,key);
//cout<<right_index<<endl;
return   left_index==-1?-1:right_index - left_index + 1;
}


int main(){
int a[]={1, 2, 3, 3, 3, 3, 10};
int n=sizeof(a)/sizeof(int);
cout<<countOccurances(a,n,4);
return 0;
}
