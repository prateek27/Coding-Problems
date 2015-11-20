#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
int n,sum=0,a[1000],count=0,distribute,i;
cin>>n;
while(n!=-1){
   for(i=0;i<n;i++)
   {
   cin>>a[i];
   sum=sum+a[i];
   }
   distribute=sum/n;
   std::sort(a,a+n);
   if(sum%distribute==0){
            for(i=0;i<n;i++)
            {
                while(a[i]>distribute)
                {
                    a[i]--;
                    count++;
                }
            }}

   else
   count=-1;


cout<<count<<endl;
count=0;
sum=0;
cin>>n;
}

return 0;

}
