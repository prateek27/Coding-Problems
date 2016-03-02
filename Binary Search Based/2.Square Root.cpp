#include<iostream>
using namespace std;

//----------------------------------------------Binary Search Method Time Complexity Log N + C*Precison
float squareRootSearch(int no,int precision){

int current_precsion =1;

int start = 0;
int end = no;
int integer_part;
int cp=0;


//Code to find the integer part.
while(start<end){

    int mid = (start+end)/2;
    int mids = mid*mid;

    if(mids<=no){
        integer_part = mid;
        start = mid+1;
    }
    else{
        end = mid-1;
    }
}
//Code to find the fractional part.
float ans = integer_part;
float fraction_part = 0;

float increment = 0.1;
while(cp < precision){

    while(ans*ans <no){
        ans +=increment;
    }
    ans -= increment;

    increment = increment/10;
    cp++;
}
return ans;
}
//-----------------------------------Newton Rhapson Method
float newtonRhapson(int n){
    float k = 1.0;
    while((k*k - n) > 0.0000000001 | (n - k * k) > 0.0000000001){
    k = (k + n / k) / 2;
    }
    return k;
}


int main(){
cout<<squareRootSearch(2,5)<<endl;
cout<<squareRootSearch(10,2)<<endl;
cout<<squareRootSearch(100,6)<<endl;
cout<<squareRootSearch(40,5)<<endl;
cout<<newtonRhapson(40)<<endl;


return 0;
}
