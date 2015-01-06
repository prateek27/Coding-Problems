#include<iostream>
using namespace std;
class Person {
    int age;
    char name[100];
    bool sex;
    public:
        Person() {
        };
        Person(char * n, int a, bool s) : age(a), sex(s) {
            strcpy(name, n);
        };
        int getAge() const {
            return age;
        }
        void setAge(int a) {
            age = a;
        }
};
class Couple {
    const Person & Husband;
    const Person & Wife;
    public:
        Couple(const Person & A, const Person & B) : Husband(A), Wife(B) {




        };
        const Person & getHusband() {
            return Husband;
        }
        const Person & getWife() {
            return Wife;
        }
};
class testConst {
    const int X;
    int Y;
    public:
        testConst() : X(0), Y(0){
        }
        testConst(int init,int C = 0) : X(init), Y(C){
        }
};
int main() {
    testConst Y, Y1(10, 20), Y2(10);
    Person H("Ranbir", 28, 1), W("Katrina", 32, 0);
    Couple C(H, W);
    Person & H1 = C.getHusband();
    cout << H1.getAge() << endl;
    cout << H.getAge() << endl;


    return 0;
}
