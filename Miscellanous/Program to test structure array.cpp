#include<iostream>
using namespace std ;


struct node{
int a[3];
};


node func(){
node n;
n.a[0]=1;
n.a[1] = 2;
cout<<&n<<endl;
cout<<&n.a[0]<<endl;
return n;
}


int main(){
node p = func();
cout<<&p<<endl;
cout<<&p.a[0];
cout<<p.a[1];

}
