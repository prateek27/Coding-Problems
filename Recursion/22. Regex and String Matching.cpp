#include<iostream>
using namespace std;


int main(){
char str[100],regExp[100];
cout<<"Enter String & Regular Expression :";
cin>>str;
cin>>regExp;

if(canAccept(regExp,str))
    cout<<"String Accepted ! ";
else
    cout<<"Not Accepted ! ";

return 0;
}
