#include<iostream>
using namespace std;

long long unsigned counter;
long long unsigned moves(int n,char,char,char);
int main(){
int n,t;
cout<<"TOWERS OF HANOI REVISITED :";
cin>>t;
while(t--){
cin>>n;
moves(n,'A','C','B');
cout<<counter<<endl;
counter=0;
}

return 0;
}
long long unsigned moves(int n,char from,char to,char aux){

if(n==0) return counter;
moves(n-1,from,aux,to);
counter++;
moves(n-1,aux,to,from);


}
