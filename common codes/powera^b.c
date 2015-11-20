#include<stdio.h>
#include<math.h>
int power(int a,int b);
int main()
{
	int n,a,num;
	n=3;
	a=3;
	num=power(a,n);
	printf("%d",num);
	return 0;
}
 
 
  int power(int a,int b)
 {   int temp;
	 if(b==0)
	      return 1;
	 if(b%2==0)
	    {
	    temp=power(a,b/2);
	    temp*=temp;  
	    }
	 else
	 {
	 	temp=a*power(a,b-1);
	 }  
	 return temp; 
 }
