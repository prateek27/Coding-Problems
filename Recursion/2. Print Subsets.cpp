#include<iostream>
using namespace std;


void printSubsets(int input[100],int output[100],int index,int subIndex,int len){

    if(subIndex==len){
        for(int k=0;k<=subIndex;k++)
            cout<<output[k]<<" ";
    }

    out[i]=a[j];
    printSubsets(a,j+1,len,i+1);
    printSubsets(a,j+1,len,i);

}


int main(){
int a[3]={1,2,3};
printSubsets(a,0,3,0);
return 0;
}
