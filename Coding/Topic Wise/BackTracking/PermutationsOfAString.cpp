#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//Note program fails if all characters are not distinct
void swap(char*a,char *b){
char temp;
temp=*a;
*a=*b;
*b=temp;
}

void permute(char a[],int i,int n){
int j;
if(i==n)
    printf("%s\n",a);
else{
for(j=i;j<=n;j++){
    swap(a+i,a+j);
    permute(a,i+1,n);
    swap(a+i,a+j);

        }
    }
}



int main(){
char a[50];
cout<<"Enter String to be permuted ";
cin>>a;
permute(a,0,strlen(a)-1);

return 0;
}
