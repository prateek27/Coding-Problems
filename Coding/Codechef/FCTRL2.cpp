#include<iostream>
#include<cstdio>
using namespace std;
/*
Take in the number of test cases
While there is a test case remaining to be handled
    Take in the number whose factorial is to be found, let it be N
    Initialize the array's 0th index to 1 and m to 1
    Initialize i to 1
    While i is less than or equal to N
       	Carry out multiplication of the array with 'i' as shown above.
    Print the contents of the array starting from the most significant digit and ending with the least significant digit.
Stop


*/
int a[200];

void factorial(int n)
{
    int i,m=1,temp=0,j,x;
    a[0]=1;

    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
        x=a[j]*i+temp;
      //  cout<<"X"<<x<<endl;
        a[j]=x%10;
        temp=x/10;
        }

        while(temp)
        {
        a[m++]=temp%10;
        temp/=10;
        }


}

     for(i=m-1;i>=0;i--)
     {
        printf("%d",a[i]);
        //cout<<"Temp"<<temp;
     }
     printf("\n");
}

int main(){
int t,n,i;
cin>>t;

while(t--)
{
scanf("%d",&n);
factorial(n);
}

return 0;
}
