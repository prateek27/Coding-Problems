#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

stack<char> myStack;
char a[405];
char ans[405];


int main(){
int n,i=0,j=0,t;
int ctr=0;
cin>>t;
while(t--){
    while(1)
    {
        for(i=0;;i++)
        {
        scanf("%c",&a[i]);
        if(a[i]=='(') ctr++;
        else if(ctr==')') ctr--;
        i++;
        if(ctr==0) break;
        }
        i=0;ctr=0;

        if(a[i]=='(')
        { ctr++;
        cout<<"Pushing";
        myStack.push(a[i]);
        }

        else if(a[i]==')'){
        ctr--;

        while(myStack.top()!='('){
        char ch=myStack.top();
        ans[j++]=ch;
        myStack.pop();
        }
    }
    else if(a[i]=='*'||a[i]=='/'||a[i]=='+'||a[i]=='-')
    {
        cout<<"PUshing"<<a[i];
        myStack.push(a[i]);
    }
    else
    {
        ans[j++]=a[i];
    }

    if(ctr==0)
    break;
}
for(i=0;i<j;i++)
    cout<<ans[i];
    cout<<endl;
    i=0;j=0;
}
return 0;
}
