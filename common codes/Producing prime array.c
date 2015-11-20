#include<stdio.h>
int main()
{
	int i,j,k,n,flag,a[100000];
	k=1;
	a[0]=2;
	for(i=3;i<=100;i+=2)
	{
		flag=0;
		for(j=0;a[j]<=i/2;j++)
		{
			if(i%a[j]==0)
			 {
			 	flag=-1;
			 	break;
			 }
		}
		if(flag==0)
		    a[k++]=i;
	}
	 printf("%d\n",k);
	for(i=0;i<k;i++)
	     printf("%d ",a[i]);
	return 0;
}
	
	     
	
