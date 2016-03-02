#include<iostream>
using namespace std;


//This works good if duplicate elements are not present :) . For duplicate elements see the next code.
int searchRecursive(int *a,int low,int high,int key){

if(high < low){
    return -1;
}
int mid = (low+high)/2;

cout<<low<<"    "<<mid<<"   "<<high<<endl;


if(key == a[mid]){
    return mid;
}

//Note less than equal to sign.
else if(a[low] <= a[mid]){
    //Left is normally ordered.
    if(key>=a[low]&& key<= a[mid]){
        return searchRecursive(a,low,mid-1,key);
    }
    else{
        return searchRecursive(a,mid+1,high,key);
    }

}
else if(a[low]>a[mid]){
    //Right is normally ordered.
    if(key >= a[mid] && key <= a[high] ){
        return searchRecursive(a,mid+1,high,key);
    }
    else{
        return searchRecursive(a,low,mid-1,key);
    }

}

}


int searchRotated(int *a,int n,int key){
int low=0;
int high = n-1;

while(low<high){
    int mid = (low+high)/2;

    if(key ==a[mid]){
        return mid;
    }
    if(high<low){ return -1;}

    cout<<a[low]<<"  "<<a[mid]<<"  "<<a[high]<<endl;


    //Left is normally ordered.
    if(a[low]<a[mid]){
        //Check for key.
        if(key>=a[low]&&key<=a[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    //Right is normally ordered.
    else if(a[low]>a[mid]){
        if(key>=a[mid]&&key<=a[high]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }

    }

}

return -1;
}


int main(){

int arr[] = {50,5,20,30,40};

int arr2[] = {10,15,20,0,5};
//Search5
//cout<<searchRotated(arr,5,5);
int ans = searchRecursive(arr2,0,4,5);
cout<<ans<<endl;
return 0;
}
