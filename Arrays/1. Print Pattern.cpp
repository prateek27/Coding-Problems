#include<iostream>
using namespace std;

// Print the given Patttern

void printPattern(int n){

int i = 0;
while(i<n){

int spaces = n-i-1;
while(spaces--) cout<<" ";

int start = i+1;
while(start<=2*i+1)
    { cout<<start; start++; }

start-=2;
int count = i;
while(count--){
cout<<start;
start--;
}
    cout<<"\n";
    i++;
    }
}


int main(){
//5 is the no of rows here
printPattern(5);
return 0;
}
