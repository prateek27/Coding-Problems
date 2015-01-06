#include<iostream>
using namespace std;

//Initialise the constants before the constructor call using initialiser list .

class testConst{
    const int X;
    int Y;

    public:
            testConst():X(0){

            }
            testConst(int init,int C=0):X(init),Y(C){

            }

};
//----------------------------Another class
class Person{    int age ;
    char name[100];
    bool sex;
    public:
        Person(){
        };
        Person(char* n,int a,bools s):name(n),age(a),sex(s){

        };
        int getAge(){
        return Age;
        }
        void setAge(int a){
            age = a;
        }

class Couple{
    Person Husband;
    Person Wife;
    public:
        Couple(Person A,Person B):Husband(A),Wife(B){
        };
    };
}
//------------------------------------------------Main
int main(){
testConst Y,Y1(10,20),Y2(10);
Person H()
return 0;
}
