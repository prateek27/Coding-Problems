#include<iostream>
#include<math.h>
using namespace std;

int main(){
int n,i,j;
int x=1;
cout<<"Enter number of lines to print ";
cin>>n;
for(i=0;i<n;i++){
    for(j=0;j<pow(2,i);j++){
        cout<<x<<" " ;
        x++;
    }

    cout<<endl;
    }
return 0;
}
