#include<iostream>
using namespace std;

class complex{
int real,imag;
public:
complex(){}
complex(int a,int b){ real=a;imag=b;}
complex operator+(complex c){
return complex(real+c.real,imag+c.imag);}
void display();
};
void complex::display(){cout<<real<<"+i"<<imag;}
int main(){
complex c1,c2,c3;
c1=complex(4,3);
c2=complex(5,7);
c3=c1+c2;
c3.display();
return 0;

}
