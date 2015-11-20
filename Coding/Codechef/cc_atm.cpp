#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
float ibalance,withdrawl,left;
cin>>withdrawl;
cin>>ibalance;
if(((int)withdrawl%5)==0)
 {
   if(withdrawl<ibalance)
    left=ibalance-withdrawl-0.50;

    else
    {
    left=ibalance;
    }
}
else
{left=ibalance;
}
cout.setf(ios::fixed);
cout<<setprecision(2)<<left;
system("PAUSE");
return 0;
  
}
