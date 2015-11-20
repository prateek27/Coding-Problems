#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){

unordered_map<char,int> m;
string s;
cout<<"Enter a string ";
cin>>s;

for(int i=0;i<s.length();i++){
    char ch = s[i];
    m[ch]++;
    }
for(int i=0;i<s.length();i++){
    char ch = s[i];

    if(m[ch]==1){
        cout<<ch;
        break;

    }
}

return 0;
}
