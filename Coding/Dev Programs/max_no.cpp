#include<iostream>
using namespace std;

int main()
{
    int num,max,min;
    char choice;
    cout<<"Enter a number : ";
    cin>>num;
    cout<<"Want to Enter more ";
    cin>>choice;
    max=min=num;
    
    
   while(choice=='y'||choice=='Y')
   {
             cout<<"Enter another number ";
             cin>>num;
             
             if(num>max)
             max=num;
            
             
             if(num<min)
             min=num;
    
             cout<<"Want to Enter more " ;
             cin>>choice;
   }
   

cout<<"\n The max no is "<<max;
cout<<"\n The min no is "<<min<<endl;
system("PAUSE");
return 0;
}
