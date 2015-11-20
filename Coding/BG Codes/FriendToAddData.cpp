//Using friend function to add data objects of two different classes
#include<iostream>
#include<conio.h>
using namespace std;

 class XYZ;//Forward Declaration
class ABC{
int data2;
public:
    void setValue(int value){
    data2 =value;
    }


};
class XYZ
{
    int data;
public:
    void setValue(int value){
    data=value;
    }


friend void add(XYZ obj1,ABC obj2){
cout<<obj1.data+obj2.data2;
}
};




int main(){
XYZ X;
ABC A;
X.setValue(20);
A.setValue(12);
add(X,A);
return 0;

}
