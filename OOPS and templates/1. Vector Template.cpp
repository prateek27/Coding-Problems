#include<iostream>
using namespace std;

#define SIZE 10


class Person{

public:
int age;
int height;
    Person(int age=0,int height=0){
    this->age = age;
    this->height = height;
    }
};
//------------------------------------------VECTOR CLASS

template<typename T>
class Vector{

T *arr ;
int top;
int size;

public:
//------------------Constructors
    Vector(){
    size = SIZE;
    arr = new T[size];
    top = -1;
    }

    Vector(int s){
    size = s;
    top = -1;
    arr = new T[size];
    }
//--------------------------------Push Back
    void push_back(T obj){

        top = top+1;

        if(top==size){

            T * temp = new T[size<<1];
            for(int i=0;i<top;i++){
                temp[i] = arr[i];
            }
            size<<=1;

            delete [] arr;
            arr = temp;
        }

        arr[top]=obj;
    }
//------------------------------Pop Back
    void pop_back(){
        top = top-1;

        if(top==size/4){
        T * temp = new T[size/2];
        for(int i=0;i<=top;i++){
        temp[i] = arr[i];
            }
        delete [] arr;
        arr = temp;
        }

    }
//----------------------------Get Back
    T back(){
        if(size>0)
        return arr[top];
    }
//----------------------------Front
    T front(){
        if(size>0)
        return arr[0];
    }
//----------------------------At
    T At(int index){
        return arr[index];
    }
//--------------------------- [] Overloading
    T &operator[](int i){
        if(i<size){
        return arr[i];
        }
    }
};



int main(){
cout<<"Int Vector :"<<endl;
Vector<int> v(2);
v.push_back(5); //5
v.push_back(6); // 5 6
v.push_back(3); // 5 6 3
v.pop_back();   // 5 6
v.push_back(4); // 5 6 4
cout<<"V1 "<<v[1]<<endl;
cout<<"Front : "<<v.front()<<endl;
cout<<"Back : "<<v.back()<<endl;

cout<<"Person Vector :"<<endl;
Vector<Person> vp ;
Person p1(5,10),p2(10,20),p3(15,30);
vp.push_back(p1);
vp.push_back(p2);
vp.push_back(p3);
cout<<vp.front().age<<endl ;
vp.pop_back();
cout<<vp.back().height;
return 0;
}

