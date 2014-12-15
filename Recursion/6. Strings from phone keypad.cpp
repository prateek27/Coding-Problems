#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
// Generates All possible strings using Phone Keypad (using 2,3,4) as input )
//Author : Prateek Narang

void generateStrings(vector<char> v[5],vector<string> &res,char *temp,int *a,int subIndex,int index,int len){


    if(index==len){
     temp[index]='\0';
     string str(temp);
     cout<<str<<endl;
     res.push_back(str);  // PUSH BACK NOt WORKING :( ...To be fixed
     return;
    }

    vector<char>::iterator it;

    for(it=v[a[index]].begin();it!=v[a[index]].end();it++){
     temp[subIndex+1]= *it;
     generateStrings(v,res,temp,a,subIndex+1,index+1,len);
    }

}

void printAllStrings(vector<string> res){
cout<<res.size()<<endl;
vector<string>::iterator it;
for(it = res.begin();it!=res.end();it++)
    cout<<(*it)<<endl;
}

int main(){
vector<char> v[5];
vector<string> res;
char temp[5];
char ch ='a';
int i;


//Insert 2- abc , 3-def , 4 - ghi
for(i=2;i<5;i++)
  {
     int count=3;
     while(count--){
     v[i].push_back(ch);
     ch++;
     }
  }
 //Find Output
int a[]={2,3,4};
int n=sizeof(a)/sizeof(int);
generateStrings(v,res,temp,a,-1,0,n);
printAllStrings(res);
return 0;
}
