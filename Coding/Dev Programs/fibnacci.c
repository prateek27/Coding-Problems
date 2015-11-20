#include<stdio.h>
#include<conio.h>

int fib(int n ){
    if(n==0||n==1)
    {
    return(1);
    }
    
    
    return (fib(n-1)+fib(n-2));
    
 
}
    
    
    

int main(){
    int n;
    
    scanf("%d",&n);
    fib(0)=1;
    fib(1)=1;
    printf("%d",fib(n)); 
     
    
    getch();
    return 0;
}
