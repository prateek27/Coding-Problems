//Generating Permutations of A String
#include<iostream>
#include<string.h>
using namespace std;
//http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

void swap(char *a,char *b){       //---------------------Simple Swapping Function
char temp;
temp=*a;
*a=*b;
*b=temp;
}


void permute(char *a,int i,int n){ //------------------Recursive Function to generate Permutations
if(i==n)
    cout<<a<<endl;
else
for(int j=i;j<=n;j++){
    swap((a+i),(a+j));
    permute(a,i+1,n);
    swap((a+i), (a+j));//----------------------------------?????????????? USE OF THIS STEP !
    }
}


int main(){
char a[20];

cout<<"Enter A String ";
cin>>a;
int n=strlen(a)-1;
permute(a,0,n);

return 0;
}

