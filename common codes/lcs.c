#include<stdio.h>
#include<string.h>
void lcs_print(char *a,int i,int j);
void lcs_length(char *a,char *b);
int k=0;
int c[2000][2000];char d[2000][2000];
void lcs(char *a,char *b,int i,int j);
int main()
{
	char a[2001],b[2001];
	int i;
	int A,B;
	scanf("%s %s",a,b);
	A=strlen(a);
	B=strlen(b);
	lcs_length(a,b);
	lcs_print(a,A,B);
	return 0;
}

void lcs_length(char *a,char *b)
{
	int i,j,A,B;
	A=strlen(a);
	B=strlen(b);
	for(i=0;i<=A;i++)
	     c[i][0]=0;
	for(i=0;i<=B;i++)
	     c[0][i]=0;	     
    for(i=1;i<=A;i++)	    
    	for(j=1;j<=B;j++)
    	{
    		if(a[i-1]==b[j-1])
    		     {
    		     c[i][j]=c[i-1][j-1]+1;
    		     d[i][j]='d';
    		     }
    		else if(c[i-1][j]>=c[i][j-1])     
    		{
    			c[i][j]=c[i-1][j];
    			d[i][j]='u';
    	    }
    		else 
			{
    			c[i][j]=c[i][j-1];
    			d[i][j]='l';
    		}
    	}
    
}
	     
void lcs_print(char *a,int i,int j)
{
	if(i==0 || j==0)
	     { 
	      return;
	  }
	if(d[i][j]=='d')      
	{
		lcs_print(a,i-1,j-1);
		printf("%c",a[i-1]);
	}
	else if(d[i][j]=='u')
	      lcs_print(a,i-1,j);
	else
	      lcs_print(a,i,j-1);      
	
}



















