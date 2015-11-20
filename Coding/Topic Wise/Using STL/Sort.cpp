#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int myArray[] = {5,3,7,9,12,16,32,1,0};

sort(myArray,myArray+9);

cout<<"The sorted Array is: ";

for(int i=0;i<9;i++)
cout<<myArray[i]<<"  ";

return 0;
}
