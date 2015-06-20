#include<iostream>
#include<climits>
using namespace std;


int merge(int *a,int,int,int);

int mergeSort(int *a,int low,int high){
int inversion_count=0;
if(low<high){
        int mid = (low+high)/2;

        inversion_count = mergeSort(a,low,mid);
        inversion_count += mergeSort(a,mid+1,high);
        inversion_count += merge(a,low,mid,high);
    }
return inversion_count;
}

int merge(int *a,int low,int mid,int high){
int temp[1000];
int l=low;
int m = mid+1;
int h=high;
int k=low;
int cnt=0;
while(l<=mid&&m<=high){
    if(a[l]<=a[m]){
        temp[k++]=a[l++];
    }
    else{
        temp[k++]=a[m++];
        cnt += mid-l+1;
        //CODE TO PRINT INVERSIONS
        for(int f=l;f<=mid;f++){
            cout<<a[f]<<","<<a[m-1]<<endl;
            }
        }
}
//Strange != Doesnt work !
while(l<=mid){
    temp[k++]=a[l++];
}
while(m<=high){
    temp[k++]=a[m++];
    }
for(int i=low;i<=high;i++){
    a[i]=temp[i];
    }
return cnt;
}

void print(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}


int main(){
int a[]={2, 4, 1, 3, 5};
int n=sizeof(a)/sizeof(int);
cout<<"No of Inversions "<<mergeSort(a,0,n-1);
//print(a,n);
return 0;
}

