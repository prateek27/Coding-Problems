6..#include<iostream>
#include<cstring>
using namespace std;

void print(char *s,int start,int last){
for(int i=start;i<=last;i++)
    cout<<s[i];
cout<<endl;
return ;
}

//This can be done recursively.
void printSubstrings(char *s,int start_index,int len){

 if(start_index==len){
    return;
 }

 for(int i=start_index;i<len;i++){
            print(s,start_index,i);
 }
printSubstrings(s,start_index+1,len);
}


int main(){
char s[20]="hello";
printSubstrings(s,0,strlen(s));
return 0;
}
