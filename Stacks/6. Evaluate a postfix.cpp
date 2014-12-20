#include<iostream>
#include<stack>
#include<cstring>
#define toInt(c) (int)(c-'0')
using namespace std;


int evaluatePostFix(char *s){

int i=0;
stack<int> st;

for(i=0;i<strlen(s);i++){

if(s[i]>=48&&s[i]<=57)
  { int x = (int)(s[i]-'0');
    st.push(x);
   }

 else{
 int n1 =0;int  n2 =0;
 if(!st.empty())
  n1 = st.top();st.pop();
 if(!st.empty())
  n2 = st.top();st.pop();

 switch(s[i]){
    case '*':st.push(n1*n2);break;
    case '/':st.push(n2/n1);break;
    case '+':st.push(n1+n2);break;
    case '-':st.push(n2-n1);break;

    }

 }
}

return st.top();
}

void print(char *a){
int i=0;
while(a[i]!='\0')
    cout<<a[i];
cout<<endl;
}

int main(){

    cout<<"Infix : (3*5+8*(9-3)/5)"<<endl;
    char postFix[] = "35*893-*5/+";
    cout<<"Postfix :"<<postFix<<endl;


    int ans = evaluatePostFix(postFix);
    cout<<"Result : "<<ans<<endl;
    return 0;
}

