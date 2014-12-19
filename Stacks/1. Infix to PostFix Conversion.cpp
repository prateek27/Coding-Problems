#include<iostream>
#include<stack>
using namespace std;

int precs

int main(){
    char p[10000];
    stack<char> s;
    int i=0;
    while(p[i]!='\0'){
        if(p[i]>=48 && p[i]<= 57 )  // If Number , print it
            cout<<p[i];
    //IF current character has higher precdence then push it , else pop
        if(s.empty() || (s.top()=='+'||s.top()=='-')&&p[i]=='*'||p[i]=='/'){
            s.push(p[i]);
        }
        else{
            while(!s.empty()||precedence(s.top())>=precdence(p[i])){
                cout<<s.top();
            }
            s.push(p[i]);
        }

    }
return 0;
}
