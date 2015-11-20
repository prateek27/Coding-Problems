#include<iostream>
using namespace std;
#define MAXSIZE 100

int main(){
int i,a[MAXSIZE],maxEndingHere=0,maxSum=0,n;
cout<<"Enter array size : ";
cin>>n;
for(i=0;i<n;i++){
    cin>>a[i];
    maxEndingHere=maxEndingHere+a[i];
    if(maxEndingHere<0)
    maxEndingHere=0;
    else if(maxEndingHere>maxSum)
        maxSum=maxEndingHere;

}
cout<<maxSum;

return 0;
}







