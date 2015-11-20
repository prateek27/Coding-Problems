#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
int myInts[]={1,1,2,3,4,5,1,6,5};
vector<int> myVector(myInts,myInts+9);
sort(myVector.begin(),myVector.end());

vector<int> :: iterator low,up;
low =lower_bound(myVector.begin(),myVector.end(),1);
up = upper_bound(myVector.begin(),myVector.end(),1);
cout<<low-myVector.begin()<<" ";
cout<<up - myVector.begin()<<" " ;

return 0;
}
