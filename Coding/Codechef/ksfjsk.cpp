#include<stdio.h>
#include<conio.h>

int product(int a,int b)
{   int ans=0;
    if(b==1)
    {
            ans=a;
            
     }
     else{
     
     ans=product(a,b-1)+a;
     }
     return ans;
} 
    

int main(){
    int a,b;
    scanf("%d,%d",&a,&b);
    product(a,b);

getch();
return 0;
}
