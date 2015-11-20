#include<iostream>
#include <fstream>
using namespace std;
#define bool int
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
void saveArray(bool* array, int length);
bool value[1000000];
int main(){

int t,i;bool temp;
int n;double height;
int k=0;
for(n=1;n<1000000;n++){
temp=0;
for(i=2;i<2*n;i+=2){
height=(double)sqrt(n*n-i*i/4);
if(height-(int)height == 0) { value[k++]=n;saveArray(value,1000000);}
}



}

return 0;
}
void saveArray(bool *array, int length)
{
    ofstream output("outputn.txt");
    for(int i=0;i<length;i++)
    {
        output<<array[i]<<",";
    }
}

