#include<iostream>
using namespace std;


void hashF(int key){
cout<<key<<endl;
}
/*
void hashF(string s){
cout<<s<<endl;
}
*/
template<typename obj>
class myClass{

public:
    void fun(const obj &a) const{
        hashF(a);
    }
};


int main(){

myClass<int> a;
a.fun(5);


}
