#include<iostream>
using namespace std;

int main()
{

    int choice ;
    float temp,newtemp;  
    cout<<"Welcome to temperature conversion menu"<<endl<<"1. Celsius to kelvin "<<endl<<"2. Kelvin to Celsius"<<endl ; 
    cout<<"Enter your choice ";
    cin>>choice ;
    cout<<"Enter the temp ";
    cin>>temp;
    if(choice==1)
    {
     newtemp=temp+273;
     cout<<"The new temp is "<<newtemp<<"K"<<endl;
     }
     else
     {
         newtemp=temp-273;
     
     cout<<"The new temp is "<<newtemp<<"C"<<endl;
     }    
    system("PAUSE"); 
    return 0;
}
