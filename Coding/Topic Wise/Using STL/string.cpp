#include<iostream>
#include<cstring>

using namespace std;

int main(){

string mystring("Hello Everyone!");
cout<<mystring<<endl;



mystring.push_back('s');
cout<<mystring<<endl;
//cout<<*(mystring.end()-1);   //To print the last character .

mystring.append("How are you ?");
cout<<mystring<<endl;


mystring.erase(7,9);
cout<<mystring<<endl;

mystring.erase(mystring.begin(),mystring.end()-2);   //
cout<<mystring<<endl;


return 0;
}
