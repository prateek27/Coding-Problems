#include<iostream>
using namespace std;

void productArray(int *a,int n,int *prod){
    int left[n];
    int right[n];

    left[0]=1;
    for(int i=1;i<n;i++){
        left[i]=left[i-1]*a[i-1];
      //  cout<<left[i]<<" ";
    }

    right[n-1]=1;
    //Mistake 1 : Started Loop from n-1 ! :(
    for(int i=n-2;i>=0;i--){
        right[i]=right[i+1]*a[i+1];
    //    cout<<right[i]<<" ";
    }

    for(int i=0;i<n;i++){
        prod[i]=left[i]*right[i];
    //    cout<<prod[i]<<" ";
    }

return ;
}
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
}

int main(){

int arr[]={10,3,5,6,2};
int n = sizeof(arr)/sizeof(int);
int prod[n];

productArray(arr,n,prod);
print(prod,n);

return 0;
}
