#include<iostream>
#include<cstring>
using namespace std;

//Rabin Karp Algorithm
/*
d : range or No of alphabets
h : d ^ m-1
m : pattern length
q: any prime no given input from main

*/

#define d 256

void search(char *pat,char *txt,int q){
int m = strlen(pat);
int n = strlen(txt);
int h = 1;
int p=0;
int t = 0;
int i,j;
for(i=0;i<m-1;i++){
    h = (h*d)%q;
    }

    for(int i=0;i<m;i++){
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            //Check for patterns
            for(j=0;j<m;j++){
            if(txt[i+j]!=pat[j]){

                break;
            }

        }
        if(j==m){
            cout<<"Found at index starting from "<<i<<endl;
            }

        }
       //Calculate the new pattern including i+m
       t = (d*(t - h*txt[i])+txt[i+m])%q;



       if(t<0){
         t = t+q;
       }
    //cout<<p<<" , "<<t<<endl;

    }
}
int main(){
    char *txt = "FGEEKS FOR GEEKS";
    char *pat = "GEEK";
    int q = 101;  // A prime number
    search(pat, txt, q);

//    getchar();
    return 0;

return 0;
}
