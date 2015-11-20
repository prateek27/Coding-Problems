#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
float ibalance,withdrawl,left;
cout<<"Enter the amount to be withdrawn"<<endl;
cin>>withdrawl;
cout<<"Enter your account balance like upto two precise digits ";
cin>>ibalance;
if(((int)withdrawl%5)==0)
 {
   if(withdrawl<ibalance)
    left=ibalance-withdrawl-0.50;

    else
    {
    left=ibalance;
    cout<<"The transaction couldnt be processed due to low account balance "<<endl;
    }
}
else
{cout<<"Enter the amount in multiple of 5$ ";
left=ibalance;
}
cout.setf(ios::fixed);
cout<<"The remaining account balance is "<<setprecision(2)<<left<<"$"<<endl;
system("PAUSE");
  return 0;
  
}
