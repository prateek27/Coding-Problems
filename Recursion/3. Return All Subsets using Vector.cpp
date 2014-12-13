#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int makeSubsets(int a[100],vector<int> *v,int array_index,int len)
{
    if(array_index==len){
        v[0].push_back(-1);
      return 1; //next index to be filled
    }

    else{
    int bucket_index = makeSubsets(a,v,array_index+1,len);
    int j,k;
    for(k=0;k<bucket_index;k++){
        for(j=0;j<v[k].size();j++)
            {
             v[bucket_index+k].push_back(v[k][j]);
            }
            //cout<<a[array_index]<<endl;
            v[bucket_index+k].push_back(a[array_index]);

        }

    return bucket_index*2;
    }
}

void printSubsets(vector<int> *v,int maxSize){

for(int i=0;i<maxSize;i++){
    cout<<"{";
    for(int j=0;j<v[i].size();j++)
        {
         if(v[i][j]==-1){
         cout<<"*,";
         }
         else
         cout<<v[i][j]<<",";
        }

    cout<<"}"<<endl;
    }
}

int main(){
int a[100];
int n;
cout<<"Enter N:";
cin>>n;

for(int i=0;i<n;i++){
cin>>a[i];
}
int maxSize = (int)(pow(2,n));
vector<int> v[maxSize];
makeSubsets(a,v,0,n);
printSubsets(v,maxSize);
return 0;
}
