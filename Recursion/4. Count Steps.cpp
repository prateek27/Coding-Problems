#include<iostream>
using namespace std;

int countSteps(int n){

if(n==1)
return 1;

if(n==2)
return 2;

if(n==3)
return 4;

else
    return countSteps(n-1)+countSteps(n-2)+countSteps(n-3);
}


int main(){
int n;
cout<<"Enter n :";
cin>>n;
cout<<"Steps Taken :";
cout<<countSteps(10)<<endl;
return 0;
}
