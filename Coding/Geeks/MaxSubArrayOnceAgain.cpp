#include<iostream>
using namespace std;

int main(){
int n;int a[100];
int maxhere = 0, maxsofar=0;
cout<<"Enter the number of numbers ";
cin>>n;

for(int i=0;i<n;i++){
cin>>a[i];
        maxhere=maxhere+a[i];
         if(maxhere<0)
            maxhere=0;
         if(maxsofar<maxhere)
            maxsofar=maxhere;
    }
cout<<maxsofar;



return 0;
}

