#include<stdio.h>
int main()
{
	int N,a[100000],i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		a[i]=1;
	for(i=2;i<=N;i++)	
		{
			for(j=i*i;j<=N;j+=i)
		        a[j]=0;
		}
		
	for(i=2;i<=N;i++)
		if(a[i]!=0)
			printf("%d ",i);
	 return 0;
}
