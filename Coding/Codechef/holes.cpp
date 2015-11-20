#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    char mystring[256];
    int holes=0,t;
    scanf("%d",&t);
   
    while(t){
    int i=0;
    scanf("%s",&mystring);
    for(i=0;i<strlen(mystring);i++)
    {              switch(mystring[i])
                  {
                    case 'A':holes=holes+1;break;
                    case 'D':holes=holes+1;break;
                    case 'O':holes=holes+1;break;
                    case 'P':holes=holes+1;break;
                    case 'Q':holes=holes+1;break;
                    case 'R': holes=holes+1;break;
                    case 'B': holes=holes+2;     
                    }
                    
   }
   printf("%d\n",holes);
   holes=0;
   t-- ;
}                   
getch();
return 0;    
}
