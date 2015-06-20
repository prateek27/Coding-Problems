#include<iostream>
#include<climits>
using namespace std;


int twoSmallestElements(int *a,int n){
int s1=INT_MAX;
int s2=INT_MAX;

for(int i=0;i<n;i++){
    if(a[i]<s1){
        s2=s1;
        s1=a[i];

    }
    else if(a[i]>s1&&a[i]<s2){
        s2=a[i];
    }
}
cout<<s1<<endl;
cout<<s2<<endl;

}

int main(){
int a[]={1, 60, 10, 70, -80, 85};
int n=sizeof(a)/sizeof(int);
twoSmallestElements(a,n);
return 0;
}

