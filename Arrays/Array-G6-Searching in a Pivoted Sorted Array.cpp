#include<iostream>
#include<algorithm>
using namespace std;



int binarySearch(int *a,int low,int high,int key){

if(low>high)
    return -1;
int mid= (low + high)/2;
if(a[mid]==key)
    return mid;
if(a[mid]>key)
    return binarySearch(a,low,mid-1,key);
else
    return binarySearch(a,mid+1,high,key);

}





int findPivot(int *a,int low,int high){
/* Remember the BASE CONDITIONS*/
if(low>high)
    return -1;
if(low==high)
    return low;

int mid=(low+high)/2;

if(mid<high&&a[mid]>a[mid+1])
    return mid;
if(mid>low&&a[mid]<a[mid-1])
    return mid-1;
if(a[mid]>a[low])
    return findPivot(a,mid+1,high);
else
    return findPivot(a,low,mid-1);
}


int findElement(int *a,int n,int key){

int pivot = findPivot(a,0,n-1);
if(key==a[pivot]){
    cout<<"Pivot is "<<pivot;
    return pivot;
}
/*This should also be noted */
else{
    if(a[0]>key){
        return binarySearch(a,pivot+1,n-1,key);
    }
    else{
        return binarySearch(a,0,pivot-1,key);
    }
}
}

int main(){
 int a[] =  {5,6,7,1,2,3,4};
   int n = sizeof(a)/sizeof(a[0]);
    //cout<<a[findPivot(a,0,n-1)];
    //cout<<binarySearch(a,0,1,6);
    cout<<"Found at Index "<<findElement(a,n,6);
return 0;
}
