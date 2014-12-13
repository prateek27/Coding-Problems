#include<iostream>
#include<cstring>
using namespace std;

char* revString(char* s,int low,int high){
if(low==high){
    return s;
    }

    swap(s[low],s[high]);
    revString(s,low+1,high-1);

}

void printRev(char *s,int low,int high){
if(low==high+1)
    {
    return;
    }

    printRev(s,low+1,high);
    cout<<s[low];
    }

int main(){
char s[100] = "Hi i am Prateek";
int n=strlen(s);
//Two ways to reverse a string
cout<<revString(s,0,n-1)<<endl;
printRev(s,0,n-1);
}
