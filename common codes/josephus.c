#include<stdio.h>
int jos(int n,int d);
int main()
{
	int N,D,jos[2],i;
	while(1)
	{
	scanf("%d %d",&N,&D);
	if(N==0 && D==0)
		break;
	jos[0]=1;
	for(i=2;i<=N;i++)	
	{
		jos[1]=(jos[0]+D-1)%i + 1;
		jos[0]=jos[1];
	}
	printf("%d %d %d\n",N,D,jos[0]);
    }
    return 0;
}
/*
int jos(int n,int d)
{
	if(n==1)
		return 1;
	else
		return (jos(n-1,d)+d-1)%n + 1;
}*/
