#include<iostream>
using namespace std;
//Tower of Hanoi Problem

void tower(int,char,char,char);

int main(){

    int n;
    cout<<"ENTER TOTAL DISKS ";
    cin>>n;
    tower(n,'A','C','B');

}

void tower(int n,char from,char to,char aux){
  if(n==1)
   {  cout<<"Moving "<<n<<" from "<<from<<" to "<<to<<endl;
      return ;
   }

   tower(n-1,from,aux,to);
   cout<<"Moving "<<n<<" from "<<from<<" to "<<to<<endl;

   tower(n-1,aux,to,from);


}
