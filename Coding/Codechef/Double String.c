#include<stdio.h>

int main(){
    int t;
    long length;
    scanf("%d",&t);
    while(t)
    {
            scanf("%li",&length);
            if(length%2==0)
            printf("%li\n",length);
            else
            printf("%li\n",length-1);
            
            t--;
    }
    
    getch();
    return 0;
}           
