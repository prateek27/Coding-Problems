#include<iostream>
#include<conio.h>
using namespace std;

class sample{
int a,b;
public:
    void setValue(void){
    a=25;b=30;
    }
    friend float mean(sample s);
};
float mean(sample s){
return float(s.a+s.b)/2.0;       //Note Friend function can't access member names directly.It users dot notation
}

int main(){
sample X;
X.setValue();
cout<<mean(X);                   //Note Friend Function is invoked like a normal function and not using object.method().Parameter is object.

}
