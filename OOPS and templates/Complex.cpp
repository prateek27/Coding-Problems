#include <iostream>
using namespace std;

class complex
{
private:
    float real;
    float imaginary;

public:
    complex()
        {real=0;imaginary=0;}
    void set_complex(float real, float imaginary);
    complex get_complex();
    void show_complex();
    complex operator+(complex c);
    complex operator~();
    friend istream &operator>>(istream & in, complex & C) {
        in >> C.real >> C.imaginary;
        return in;
    }
    friend ostream & operator<<(ostream & out, complex & C) {
        out<<"Complex number is: "<<C.real<<"+ i"<<C.imaginary<<endl;
        return out;
    }
     
};


void complex::show_complex()
{
    cout<<"Complex number is: "<<real<<"+ i"<<imaginary<<endl;
}

void complex::set_complex(float r1, float i1)
{
    real=r1;
    imaginary=i1;
}

complex complex::operator+(complex c)
{
    complex temp_complex;
    temp_complex.real=real+c.real;
    temp_complex.imaginary=imaginary+c.imaginary;
    return temp_complex;
}

complex complex::operator~()
{
    complex temp_complex;
    temp_complex.real=real;
    temp_complex.imaginary=-1*imaginary;
    return temp_complex;
}

int main()
{ 
    complex c1,c2,c3;
    c1.set_complex(2,3);
    c1.show_complex();
    c2.set_complex(4,5);
    c2.show_complex();
    c3=c1+c2;//c3=c1.operator+(c2)
    c3.show_complex();
    c3=~c3;
    c3.show_complex();
    cin >> c1;
    cout << c1 << "Hi" << endl;
    return 0;
}


