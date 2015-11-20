#include<iostream>
#include<bitset>
using namespace std;

//http://www.cplusplus.com/reference/bitset/bitset/bitset/

int main(){
bitset<16> bitset1(0);
bitset<16> bitset2(10);
bitset<16> bitset3(string("1110"));

bitset1[1]=1;
cout<<bitset1<<endl;
cout<<bitset2<<endl;
cout<<bitset3<<endl;

return 0;
}
