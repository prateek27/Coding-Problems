#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<list>
using namespace std;

bool compare(const char&a,const char&b){
//Swap if a is less then b => Return true.
return a<b;
}

//--------------------------------------Returns a new string after sorting a string s.
string getKey( string s){
//Returns the sorted version of string s.
int len = s.length();
char *chararray = new char(len);
for(int i=0;i<len;i++){
    chararray[i] = s[i];
}
sort(chararray,chararray+len,compare);
//cout<<chararray<<endl;
string newstring(chararray);
delete [] chararray;
return newstring;
}

bool compareForArray(const string&s1,const string&s2){
    return getKey(s1)==getKey(s2)?true:false;
}
//-----------------------------------------Actual function that sorts strings based on
void sortArray(string *s,int n){
// This fails.
//sort(strings,strings+n,compareForArray);
map<string,vector<string> > m ;

for(int i=0;i<n;i++){
    m[getKey(s[i])].push_back(s[i]);
}

map<string,vector<string> > :: iterator it;

int index = 0;

for(it = m.begin();it!=m.end();it++){
    for( int j =0;j< (*it).second.size();j++){
        cout<<it->second[j]<<endl;
        s[index++] = it->second[j];
    }
cout<<endl;
}


}



int main(){

string s[10] = {"ab","ca","cac","ba","bba","cca","abb"};
int n = 7;

sortArray(s,n);

cout<<"Original List after Modifiying is -"<<endl;
for(int i=0;i<n;i++){
cout<<s[i]<<" ";
}

//getKey("cabaaaa");

//Anagrams should be next to each other.


return 0;
}
