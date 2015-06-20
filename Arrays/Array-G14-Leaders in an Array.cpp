#include<iostream>
using namespace std;


void findLeaders(int *a,int n){

    int leader = a[n-1];
    cout<<leader<<endl;
    int i;
    for(i=n-2;i>=0;i--){
        if(a[i]>leader){
            leader = a[i];
            cout<<a[i]<<endl;
            }

    }

}

int main(){
int a[]={16, 17, 4, 3, 5, 2};
int n=sizeof(a)/sizeof(int);
findLeaders(a,n);
return 0;
}
