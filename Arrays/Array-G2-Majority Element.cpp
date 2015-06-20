#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// Brute Force : O(n square) , O(1)

// BST : Add nodes to BST , increment their frequencies

// Moore's Voting algorithm
int findMajorityElement(int *a,int n){

int maj_index = 0;
int count = 1;

for(int i=1;i<n;i++){
    if(a[i]==a[maj_index])
        count++;
    else
        count--;
    if(count==0){
        maj_index=i;
        count=1;
    }
}
count=0;
for(int i=0;i<n;i++){
    if(a[i]==a[maj_index])
        count++;
}
if(count>n/2)
    return a[maj_index];
else{
    cout<<"NONE";
    return -1;
}

}


int main(){
int a[] = {2, 2, 3, 5, 2, 2, 6};
int n= sizeof(a)/sizeof(int);
cout<<findMajorityElement(a,n);
return 0;
}
