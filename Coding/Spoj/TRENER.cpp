#include<iostream>
using namespace std;

int main(){
char name[150][30];
int freq[26];
char alphabets[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int n,i;
cin>>n;
 for(i=0;i<26;i++){
        freq[i]=0;}

for(i=0;i<n;i++){
cin>>name[i];
freq[toascii(name[i][0])-97]++ ;
//cout<<name[i]<<endl;
}
int var=1;
for(i=0;i<26;i++){

        if(freq[i]>=5){
         cout<<alphabets[i];
         var=0;
        }
}
if(var)
cout<<"PREDAJA";





return 0;
}
