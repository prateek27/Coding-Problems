#include<iostream>
using namespace std;


void printSubsets(int input[100],int output[100],int len,int index,int subIndex){

    if(index==len){
        cout<<"{";
        for(int k=0;k<=subIndex;k++)
            cout<<output[k]<<",";
        cout<<"-}"<<endl;
        return ;
    }

    output[subIndex+1]=input[index];
    printSubsets(input,output,len,index+1,subIndex+1);
    printSubsets(input,output,len,index+1,subIndex);
}


int main(){
int a[100]={1,2,3};
int output[100];
printSubsets(a,output,3,0,-1);
return 0;
}
