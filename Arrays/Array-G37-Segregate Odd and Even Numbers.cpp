#include<iostream>
using namespace std;

/*
Input = {12, 34, 45, 9, 8, 90, 3}
Output = {12, 34, 8, 90, 45, 9, 3}
Put Even numbers first
*/

void segregate(int *a,int n){

int low=0;
int high=n-1;
while(low<high){
    while(a[low]%2==0 && left<right){
        low++;
    }
    while(a[high]%2==1 && left<right){
        high--;
    }

    if(left<right)
        swap(a[low++],a[high--]);
}

return ;
}
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ,";
    }

}

int main(){
int a[]={12, 34, 45, 9, 8, 90, 3};
int n = sizeof(a)/sizeof(int);
segregate(a,n);
print(a,n);
return 0;
}
