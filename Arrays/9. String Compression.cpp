#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

string compressIt(string s){
char a[1000];
int j=0;
string s2;
int len = s.length();
int i;
for(i=0;i<len;){
char current = s[i];
int count=1;

while(s[i]==s[++i]){
count++;
}
s2.push_back(current);
char cnt = (char)(((int)'0')+count);
s2.push_back(cnt);

}
return s2;
}

int main(){
string s = "aaabbcddeeee";
cout<<compressIt(s);
return 0;
}
