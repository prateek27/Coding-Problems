#include<iostream>
using namespace std;

int p[1000000][1000000];
int main(){

for(i=1;i<1000;i++)
{
for(j=i+1;j<1000;j++)
p[i][j]=i*i+j*j;
}



return 0;
}
