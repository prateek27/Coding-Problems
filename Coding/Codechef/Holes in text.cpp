#include<stdio.h>
#include<conio.h>

int main(){
    int t,i,holes;
    char a[101];
    
   
    
             holes=0;
             for(i=0;a[i]!='\0';i++){
             scanf("%c",&a[i]);
             
             
             switch(a[i]){
                          
                          case 'A':
                          case 'D':
                          case 'O':
                          case 'P':
                          case 'Q':               
                          case 'R':holes=holes+1;break;
                          case 'B':holes=holes+2;break;
                          }
                          
                          }
                          printf("%d\n",holes);
             
            
            
             
             
getch();
return 0;
}
