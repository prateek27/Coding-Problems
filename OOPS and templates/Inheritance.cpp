#include<iostream>
using namespace std;
class A{
    public:
        int a;
        void setb() {
            b = 10;
        }
        int getb() {
            return b;
        }
    private:
        int b;
    protected:
        int c;

};
class B: public A {
    public:
        void set() {
            a = 10;
            setb();
            c = 30;
        }

};
class C: public B {
    public:
        void set() {
            cout << "In SET" << endl;
            c = 10;
        }
};
int main() {
    B a1;
    C a2;
    a1.set();
    
    cout << a1.getb() << endl;
    a1.a = 100;
    a2.set();
    cout << a1.a << endl;
}

