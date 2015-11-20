#define max_n 100010
char T[max_n],P[max_n];//T=text    P=pattern
int b[max_n],n,m;// b=back table  n=length of T   m=length of P
void kmppre()
{
	i=0;j=-1;b[0]=-1;//notice that b[i] attains value before checking for P[i]
	while(i<m)
	{
		if(j>=0&&P[i]!=P[j])
			j=b[j];
		i++;
		j++;
		b[i]=j;
	}
}
void kmpsearch()
{
	int i=0,j=0;
	while(i<n)
	{
		while(j>=0&&T[i]!=P[j])
			j=b[j];
		i++;
		j++;
		if(j==m)
		{
			printf("Pattern found at index %d \n",i-j );
			j=b[j-1];//in book given b[j]
		}	
	}
}
