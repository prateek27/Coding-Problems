#include<iostream>
#include<cstring>
#include<map>
using namespace std;

//This generates all the permutations of an array(character array)

//To avoid duplicate permuations , we can use the map.
//If the generated string already exists(map.count(s)>0) in the map , then dont push.
map<string,bool> m;

void printPermutation(char *s,int index,int len){
if(index==len){
    if(m.count(s)==0)
        m[s]=true;
}
else{
    for(int i=index;i<len;i++){
        swap(s[i],s[index]);
        printPermutation(s,index+1,len);
        swap(s[index],s[i]);
        }
    }
}

void printMap(){

    map<string,bool>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<endl;
    }
}


int main(){
char s[]="abcd";
int n=strlen(s);
printPermutation(s,0,n);
printMap();
return 0;
}
