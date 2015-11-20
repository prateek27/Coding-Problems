#include<iostream>
using namespace std;

int main(){
int n,m,i,j=0,sum=0,psum=0;

cin>>n>>m;
int a[n];

for(i=0;i<n;i++){
cin>>a[i];

}



for(i=0;i<n;i++){
   sum=sum+a[i];

  if(sum>m){

    do {
    sum=sum-a[j];
    j++;

    continue ; }
    while(sum>m);


  }
if(sum>psum){ psum = sum ; }



}

cout<<psum<<endl;
return 0;
}
