#include<iostream>
#include<cstdlib>
using namespace std;


unsigned min(unsigned a,unsigned b,unsigned c);
unsigned getUglyNumber(unsigned n)
{
unsigned *ugly=(unsigned*)(malloc(sizeof(unsigned)*n));
unsigned i;
unsigned next2=2,next3=3,next5=5,nextUgly=1;
unsigned i2=0,i3=0,i5=0;
*(ugly+0)=1;

for(i=1;i<n;i++)
{
    nextUgly=min(next2,next3,next5);
    *(ugly+i)=nextUgly;

    if(nextUgly==next2){
        i2++;
        next2=*(ugly+i2)*2;
        }
    if(nextUgly==next3){
        i3++;
        next3=*(ugly+i3)*3;
        }
     if(nextUgly==next5){
        i5++;
        next5=*(ugly+i5)*5;
    }



}
 return nextUgly;
}
unsigned min(unsigned a,unsigned b,unsigned c)
{
    if(a <= b)
    {
      if(a <= c)
        return a;
      else
        return c;
    }
    if(b <= c)
      return b;
    else
      return c;
}



int main()
{
    int n;
   cout<<"Enter n ";
   cin>>n;

   cout<<getUglyNumber(n);


}
