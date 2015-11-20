#include<iostream>
#include<math.h>
using namespace std;
float fun(int n)
{
	long sum;
	for(int i=n; i>1;i--)
		sum+=log(i);
	return sum;
}
int main()
{
	int t, a, n;
	float p, q;
	while(t--)
	{
		cin>>a;
			for(n=1; ; n++)
			{
				p=n*log(a);
				q=fun(n);
				if(q>p)
				{
					cout<<n<<endl;
					break;
				}
			}
	}
	return 0;
}
