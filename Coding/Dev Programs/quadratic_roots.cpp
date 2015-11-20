#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    /*Roots of a Quadratic Equation */
    
    int a,b,c,d;
    float r1,r2;
    cout<<"Enter coefficients a,b,c of equation  ax^2+bx+c : "<<endl;
    cin>>a>>b>>c;
    
    d=b*b-4*a*c;
    if(d>0)
    {
           cout<<"Roots are real and distinct "<<endl;
           r1= (-b+sqrt(d))/2*a;
           r2=(-b-sqrt(d))/2*a;
           cout<<"Roots are " <<r1<<" and "<<r2<<endl;
    }      
    
    else if(d==0)
    {
         cout<<" Roots are real and equal "<<endl;
         r1=-b/2*a  ;
         cout<<"Roots are "<<r1<<" and "<<r1<<endl;
    }
    else
    cout<<"Imaginary roots "<<endl;
    
    
    
    system("PAUSE");
    return 0;
    
}
