#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;


int fun(long long n){
long long i;double height;
long long k=n*n;
for(i=2;i<2*n;i+=2){
height=(double)sqrt(k-i*i/4);
if(height-(int)height == 0)  return 1 ;
}
return 0;
}



int main(){
long long n;
ofstream output("outputF.txt");
for(n=2;n<10000000;n++)
    {
        cout<<fun(n)<<",";

    }

return 0;
}

