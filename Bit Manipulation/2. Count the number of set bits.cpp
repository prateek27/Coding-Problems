#include<iostream>
using namespace std;

int countBits(int no){
    int mask=1;
    int count=0;
    while(mask){
        if(mask&no)
            count++;
        mask = mask<<1;
    }
return count;
}


int main(){

int no;
cin>>no;
cout<<"The of set bits in "<<no<<" are "<<countBits(no);
return 0;
}
