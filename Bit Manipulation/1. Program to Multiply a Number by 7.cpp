#include<iostream>
using namespace std;

int multiply(int no){

return no*(1<<3) - no;

}

int main(){

int n;
cin>>n;
cout<<multiply(n);

return 0;
}
