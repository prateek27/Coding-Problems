#include<iostream>
#include<stack>
using namespace std;

bool checkBalanced(char *p){

stack<char> s;
int i=0;
while(p[i]!='\0'){
    if(p[i]=='['|| p[i]=='{'||p[i]=='(')
      { s.push(p[i]); i++ ;}

    else {
        switch(p[i]){
            case ']':   if(s.top()=='[')
                        {s.pop(); i++;}
                        else
                        { return false ; }
                        break;
            case '}':   if(s.top()=='{')
                            { s.pop(); i++ ;}
                       else{
                            return false;
                            }
                       break;

            case ')':   if(s.top()=='(')
                        { s.pop(); i++ ; }
                       else{
                       return false; }
                       break;
            default : i++;

        }
    }
}

if(!s.empty())
    cout<<"NOT EMPTY";
return true;
}


int main(){

char* s = "[{a+b}*5[25*7]3()]";

if(checkBalanced(s))
    { cout<<"Balanced ! " ; }
else
    cout<<"Ooops .. Not Balanced! ";

return 0;
}
