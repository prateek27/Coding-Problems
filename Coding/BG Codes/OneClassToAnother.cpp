#include<iostream>
using namespace std;

class invent2;

class invent1{
int code;
int items;
int price;

public:
    invent1(int c,int i,int p)
    {
        code=c;
        items=i;
        price=p;
    }
    int getcode(){return code;}
    int getitems(){return items;}
    int getprice(){return price;}
};

  class invent2{
   int code,value;
   public:
        invent2(int x,int y){
         code=x;
         value=y;
     }

     void display(){cout<<"Code:"<<code<<endl;cout<<"Value"<<value<<endl;}

     invent2(invent1 p)
     { code=p.getcode();                   //getcode methods
       value=p.getitems()*p.getprice();
     }
};

int main(){
invent1 one=invent1(1,2,3);
invent2 two=invent2(one);
two.display();
return 0;
}
