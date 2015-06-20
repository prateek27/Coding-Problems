#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void checkForPair(int *a,int n,int sum){

    int l=0,r=n-1;
    while(l<r){
        if(a[l]+a[r]==sum){
            cout<<"Pair found "<<a[l]<<" & "<<a[r]<<endl<<endl;
            return;
        }
        else if(a[l]+a[r]<sum){
            l++;
        }
        else{
            r--;
        }
    }
cout<<"No such pair found"<<endl<<endl;
return;
}

void checkUsingMap(int *a,int n,int sum){
unordered_map<int,bool> myMap;
for(int i=0;i<n;i++){
    myMap[a[i]]=true;
}

for(int i=0;i<n;i++){
    if(myMap[sum-a[i]]==true)
        cout<<"Pair found in Map "<<a[i]<<" and "<<(sum-a[i])<<endl;
}
return;
}

int main(){
int a[] = {-8, 1, 4, 6, 10, 45};
int n= sizeof(a)/sizeof(int);
int sum = 16;
checkForPair(a,n,sum);
checkUsingMap(a,n,sum);
return 0;
}
