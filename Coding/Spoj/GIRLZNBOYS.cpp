#include<iostream>

using namespace std;

int ceil(int a,int b)
{
    if(a%b==0)
        return a/b;
        else
            return a/b+1;
}

int main(){
int a,b;
cin>>a>>b;
while(a!=-1&&b!=-1){

   if(a==0&&b==0){cout<<"0"<<endl;}
   else if(a==b) { cout<<"1"<<endl;}

   if(a>b){ cout<<ceil(a,b+1) ; cout<<endl; }

   else if (b>a) { cout<<ceil(b,a+1) ; cout<<endl;}

   cin>>a>>b;
   }


return 0;
}
