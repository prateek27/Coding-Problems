#include<iostream>
using namespace std;

int p[1000][1000];
int main(){
int i,j;
for(i=1;i<1000;i++)
{
for(j=i+1;j<1000;j++)
p[i][j]=i*i+j*j;
}



return 0;
}
