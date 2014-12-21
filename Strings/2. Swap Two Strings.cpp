#include<iostream>
using namespace std;

void swapStrings(char **a,char **b){
char *temp =*a;
*a=*b;
*b=temp;
return;
}

int main(){
char *a = "Physics ";
char *b = "I love ";
cout<<a<<b<<endl;
swapStrings(&a,&b);
cout<<a<<b<<endl;
return 0;
}
