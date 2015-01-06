#include<iostream>
using namespace std;
class Person {
    int age;
    char name[100];
    static int population;
    public:
    Person() {
       population++;
    }
    static int getPopulation() {
        return population;
    }
    void Print() {
        cout << "name " << name;
        cout << "age" << age;
    }
    static void Print(Person A) {
        cout << A.age << endl;
        cout << A.name << endl;
    }
};
int Person::population = 0;
int main() {
    Person A, B, C;
    cout << Person::getPopulation() << endl;
    cout << Person::getPopulation() << endl;
    Person D,E;
    cout << Person::getPopulation() << endl;
    return 0;
}
