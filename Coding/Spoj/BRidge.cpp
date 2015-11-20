#include<iostream>
#include<map>
#include<cstdio>
#define readint(n) scanf("%lld",&n)
#include<algorithm>
#define int long long
using namespace std;
int a[2005];
int b[2005];
int lis[2005];

map<int,int> myMap;

int LIS(int arr[], int n )
{

int i,j,max=0;
   for ( i = 0; i < n; i++ )
    lis[i] = 1;


   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;


   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];

return max;
}


main(){
int t,n;
int i,j;
readint(t);
while(t--)
{
readint(n);
for(i=0;i<n;i++)
    readint(a[i]);

for(i=0;i<n;i++){
    readint(b[i]);
    myMap[b[i]] = a[i];
    }
    sort(b,b+n);
    for(i=0;i<n;i++){ a[i]=myMap[b[i]];}

/*for(i=0;i<n;i++) cout<<a[i]<<" ";
cout<<endl;
for(i=0;i<n;i++) cout<<b[i]<<" ";
*/

printf("%lld\n",LIS(a,n));
}
return 0;
}

