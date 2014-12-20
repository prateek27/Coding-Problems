o#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

//Note Post Fix of a%b = ba%

int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

void infixToPostFix(char *p){

    char postFix[100];
    stack<char> s;
    int i=0;
    int k=0;
    int count = 0;
        while(count<strlen(p)){
           cout<<p[i];
          count++;
        if(p[i]>=48 && p[i]<=57)  // If Number , print it
            postFix[k++] = p[i];

        else if(p[i]=='('){
            s.push('('); i++;
        }
        else if(p[i]==')'){
            while(!s.empty()&&s.top()!='('){
                postFix[k++] = s.top();
                s.pop();
            }
            if (!s.empty() && s.top()!= '(')
                return ; // invalid expression
            else
                s.pop();


        }
        else{
            while(!s.empty()&&prec[p[i]]<=prec[s.top()]){
                postFix[k++]=s.top();
                s.pop();
            }
         cout<<"Pushing"<<p[i];
        s.push(p[i]);
        i++;
        }
    }
    while(!s.empty()){
    postFix[k++] = s.top();
    s.pop();
    }
    postFix[k]='\0';
//cout<<postFix<<endl;
return ;
}

void print(char *a){
int i=0;
while(a[i]!='\0')
    cout<<a[i];
cout<<endl;
}

int main(){

    char p[] = "(3+3)";

    infixToPostFix(p);
    return 0;
}
