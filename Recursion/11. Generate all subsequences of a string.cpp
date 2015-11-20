#include<iostream>
#include<cstring>
using namespace std;

void print(char *s,int start,int last){
for(int i=start;i<=last;i++)
    cout<<s[i];
cout<<endl;
return ;
}

//This can be done recursively.
void printSubsequences(char *s,char *temp,int start_index,int temp_index,int len){

 if(start_index==len){
    cout<<temp<<endl;
    return;
 }

 temp[temp_index+1]= s[start_index];
 printSubsequences(s,temp,start_index+1,temp_index+1,len);

 temp[temp_index+1]='\0'; //Terminating the string is important.
 printSubsequences(s,temp,start_index+1,temp_index,len);
}


int main(){
char s[20]="abc";
char temp[20];
int len = strlen(s);
printSubsequences(s,temp,0,-1,len);
return 0;
}

