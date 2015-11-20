#include<bits/stdc++.h>
#include<list>
#include<vector>
using namespace std;


vector<int> v;

void countInversion(list<int> l){
int count=0;
int n = l.size();

list<int>::iterator it;

list<int>::iterator j;
for(it = l.begin();it!=l.end();it++){
   j = it++;
   for(;j!=l.end();j++){
        if((*it)>(*j)){
            count++;
        }

   }

}
v.push_back(count);
return;
}

void CountHappy(int *a,list<int> &l,int n,int i,int j){

if(i>j){
  //Calculate unhappiness for the formed arrays
    countInversion(l);
    return;
}
l.push_front(a[i]);
CountHappy(a,l,n,i+1,j);
l.pop_front();

l.push_front(a[j]);
CountHappy(a,l,n,i,j-1);
l.pop_front();

l.push_back(a[j]);
CountHappy(a,l,n,i,j-1);
l.pop_back();


l.push_back(a[i]);
CountHappy(a,l,n,i+1,j);
l.pop_back();
}


int main(){
int a[1000];
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
list<int> l;
CountHappy(a,l,n,0,n-1);
int minV =10000;
for(int i=0;i<v.size();i++){
    if(v[i]<minV){
        minV = v[i];
    }
cout<<v[i]<<",";
}

cout<<minV;
return 0;
}
