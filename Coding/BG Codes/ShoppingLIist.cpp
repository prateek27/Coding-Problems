#include<iostream>
#include<conio.h>
using namespace std;

const int m=50;
class ITEMS{
int itemCode[m];
float itemPrice[m];
int count;

public:
    void CNT(void){count=0;}
    void getItem(void);
    void diplaySum(void);
    void remove(void);
    void displayItems(void);

};

void ITEMS::getItem(void){
cout<<"Enter Item Code";
cin>>itemCode[count];
cout<<"Enter Item price ";
cin>>itemPrice[count];
count++;
}

void ITEMS::diplaySum(void){
float sum=0;
for(int i=0;i<count;i++){
    sum=sum+itemPrice[i];
    cout<<"\n Total amount : "<<sum;

}
}

void ITEMS::remove(void){

int a;
cout<<"Enter item code";
cin>>a;
for(int i=0;i<count;i++)
{
    if(itemCode[i]==a)
        itemPrice==0;
}}

void ITEMS::displayItems(void){
cout<<"\n Code Price\n";
for(int i=0;i<count;i++){
    cout<<"\n"<<itemCode[i];
    cout<<" "<<itemPrice[i];
}
cout<<"\n";
}

int main()
{
    ITEMS order;
    order.CNT();
    int x;
    do
    {
      cin>>x;

    switch(x)
    {
        case 1:order.getItem();break;
        case 2:order.diplaySum();;break;
        case 3:order.remove();break;
        case 4:order.displayItems();break;
        case 5:break;
}}
while(x!=5);
return 0;
}

