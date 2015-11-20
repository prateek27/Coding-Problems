#include<stdio.h>
int main()
{
    int x;
    float y;
    scanf("%d%f",&x,&y);
    if(x%5==0&&y-x>=0.50)
    printf("%0.2f",y-x-.50);
    else
    printf("%0.2f",y);
    
    return 0;
    
}
    
