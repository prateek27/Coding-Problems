#include<iostream>
using namespace std;

// Returns location of key, or -1 if not found
int BinarySearchFast(int A[], int l, int r, int key)
{
    int m;

    while(r-l>1)
    {
        m = l + (r-l)/2;

        if( A[m] <= key ) // first comparison
            l = m;
        else
            r = m ;
    }
    if(A[l]==key){
        return l;
    }
    else{
        return -1;
    }
}

int main(){

int arr[] = {0,1,2,3,4,5,6,7,8,9};

for(int key =0;key<=10;key++){
    cout<<BinarySearchFast(arr,0,10,key)<<endl;
}



return 0;
}
