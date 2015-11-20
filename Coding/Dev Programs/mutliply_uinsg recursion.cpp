#include<stdio.h>
#include<conio.h>

int multiply(int a,int b ){
    if(b==1)
    return(a);
    
    return (a+multiply(a,b-1));
    
 
}
    
    
    

int main(){
    int a,b;
    scanf("%d",&a); 
    scanf("%d",&b);
     
     
    printf("%d",multiply(a,b));
    getch();
    return 0;
}
