#include<iostream>
#include<stack>
using namespace std;

// ??? Dont know what to do .
removeDuplicateParenthesis(char *a,int n){
    stack<char> s;
    char b[100];
    int i=0;
    int j=0;
    while(a[i]!='\0'){
        if(a[i]=='('){
            b[j++] = '('
            s.push('(');
        }
        else if(a[i]==')'){
        while(s.top()!='('){
                count++;
                s.pop();
            }

        }


    i++;
    }

}

int main(){
char a[] ="((a+b)+ ((c-d)))";
int  n = sizeof(a)/sizeof(char);
removeDuplicateParenthesis(a,n);

return 0;
}
