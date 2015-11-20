// Takes two times and adds them
#include<iostream>

#include<conio.h>
using namespace std;

class time{
int hours;
int mins;

public:
    void getTime(int h,int m){
    hours=h;
    mins=m;
    }
    void puttime(void){
    cout<<hours<<" hours and"<<mins<<" mins";
    }
    void sum(time,time);               //Arguments of the type class
};
void time::sum(time t1,time t2)
{
      mins=t1.mins+t2.mins;
      hours=mins/60;
      mins=mins%60;

      hours=hours+t1.hours+t2.hours;
 }

 int main()
 {
     time t1,t2,t3;
     t1.getTime(2,30);
     t2.getTime(3,40);
     t3.sum(t1,t2);

     cout<<endl;  t1.puttime();
     cout<<endl;  t2.puttime();
     cout<<endl;
         t3.puttime();

     return 0;
 }
