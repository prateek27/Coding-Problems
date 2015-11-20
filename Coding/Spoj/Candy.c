#include<stdio.h>

int main(){
int n,sum=0,a[1000],count=0,distribute,i;
scanf("%d",&n);
while(n!=-1){
   for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   sum=sum+a[i];
   }

   if(sum%n==0){
   distribute=sum/n;
       for(i=0;i<n;i++){
           if(a[i]>distribute)
           count=count + (a[i]-distribute);
           }
           printf("%d\n",count);
    }
    else
        printf("-1\n");
count=0;
sum=0;
scanf("%d",&n);
}

return 0;

}
