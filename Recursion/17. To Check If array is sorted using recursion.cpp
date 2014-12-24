#include<iostream>
using namespace std;

bool isSorted(int *a,int n){

}


int main(){
int a[] ={1,3,5,7,6,9,10,15,20};
int n = sizeof(a)/sizeof(a[0]);
if(isSorted(a,n))
    cout<<"Sorted!";
else
    cout<<"Not Sorted !";

}
