#include<iostream>
using namespace std;
//This is the recursive version of subset sum problem
//Author:Prateek Narang

void print(int *a,int len){
    int sum=0;
if(len==3){	    
for(int i=0;i<len;i++){
        sum+=a[i];
        cout<<a[i]<<"+";
    }
    cout<<"="<<sum<<endl;
}

}
//-----------------------------------------------------------------Recursive Subset Sum
void subsetSum(int *a,int *temp,bool *flag,int array_index,int temp_index,int sum,int len){


if(array_index==len&&sum==0)
{
    *flag=true;
    print(temp,temp_index);
    return;
}
if(array_index==len&&sum!=0)
    return;

if(a[array_index]>sum)  //Optional Condition , used for Optimization
    subsetSum(a,temp,flag,array_index+1,temp_index,sum,len);

else{
    temp[temp_index]=a[array_index];
    subsetSum(a,temp,flag,array_index+1,temp_index+1,sum-a[array_index],len);
    temp[temp_index]=0;  //OPTIONAL STATEMENT
    subsetSum(a,temp,flag,array_index+1,temp_index,sum,len);
    }
}

//--------------------------------------------------------------Main
int main(){

int a[] = {1,2,3,4,5};
int n = sizeof(a)/sizeof(a[0]);
int temp[100];
int sum=9;
bool flag=false;
subsetSum(a,temp,&flag,0,0,sum,n);

if(flag==false){
 cout<<"No Subsets Found !"<<endl;
}
return 0;
}
