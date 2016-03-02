#include<iostream>
#include<cstring>
using namespace std;

//Space ko Replace %22d
// Double Quotes ko %5d


string escaper(string str){
int quotes = 0;
int spaces = 0;

int len = str.length();
for(int i=0;i<len;i++){
    if(str[i]==' ')
        spaces++;
}

char *temp = new char[len + 2*spaces+1];
int last = len + 2*spaces;
temp[last] = '\0';

for(int i=len-1;i>=0;i--){
    if(str[i]==' ' ){
        temp[last-1] = '0';
        temp[last-2] = '2';
        temp[last-3] ='%';
        last = last-3;
    }
    else{
        temp[last-1]= str[i];
        last--;
    }

}
string *s = new string(temp);
delete temp;

return *s;
}



int main(){

string s ="he llo world";
cout<<escaper(s);
return 0;

}
