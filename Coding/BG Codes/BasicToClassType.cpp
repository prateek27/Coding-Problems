#include<iostream>
using namespace std;
//Constructors are used.
class time{
int hours,mins;
public:
time(int t)
{
hours=t/60;
mins=t%60;
}
operator int();
void display();
};
void time::display(){
cout<<hours<<":"<<mins;
}

time::operator int()
{
int sum=hours*60+mins;
return sum;
}


int main()
{
time t1=time(80);
t1.display();
cout<<endl<<int(t1)<<"mins";
return 0;
}
