#include<iostream>
using namespace std;

int main()
{
    //Program to check a string is palindrome or not

char name[101];
int len;
cout<<"Enter your string "<<endl;
cin.getline(name,101);

for(len=0;name[len]!='/0';++len);
int i,j,flag=1;

for(i=0,j=len-i;i<len/2;++i,--j)
{
      if(name[i]!=name[j])
      {
           flag=0;
           break;
      }
}
if(flag)
cout<<" It is a palindrome";
else
cout<<"Not a palindrome ";

system("PAUSE");
return 0;
}
