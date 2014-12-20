#include<iostream>
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
    cout<<"Original : "<<p<<endl;
    cout<<"Postfix  : ";
    for(int i=0;i<strlen(p);i++){
        //Left Bracket, Push it
        if(p[i]=='(')
            { s.push('('); }
        //Right Bracket , Pop All
        else if(p[i]==')'){
            while(s.top()!='('&&!s.empty())
             {   cout<<s.top();
                s.pop();}
         s.pop();
        }
        //Number , Out as it
       else if(p[i]>=48&&p[i]<=57)
       { cout<<p[i] ; }
        //Operand : Two cases arise
       else{
        //Higher Precedence Push It or Stack is Empty
        if(s.empty()||prec(s.top())<prec(p[i]))
                   {s.push(p[i]); }
        else{
            //Pop the characters until a current has precedence lower or equal to that of top
        while(!s.empty()&&(prec(s.top())>=prec(p[i]))){
        cout<<s.top();
        s.pop();

        }
            s.push(p[i]);
            }
        }
    }
    //Last step empty the stack
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

return ;
}

void print(char *a){
int i=0;
while(a[i]!='\0')
    cout<<a[i];
cout<<endl;
}

int main(){

    char p[] = "(3*5+8*(9-3)/5)";

    infixToPostFix(p);
    return 0;
}
