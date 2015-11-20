#include<stdio.h>

int main()
{
    int x;
    float y;
    int t;
    scanf("%d",&t);
    while(t--){

    scanf("%d%f",&x,&y);
    if(x%5==0&&y-x>=0.50)
    printf("%0.2f\n",y-x-.50);
    else
    printf("%0.2f\n",y);
    }
    return 0;

}
