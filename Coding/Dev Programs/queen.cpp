#include<stdio.h>
#include<conio.h>
int main()
{
    int i , j=0;
    char chess[4][4]={'1','1','1','1',
                       '1','1','1','1',
                       '1','1','1','1',
                       '1','1','1','1'};
    
                 
                               
                 for(i=0;i<4;i++){
                 
                 for(j=0;j<4;j++){
                       if(chess[i][j]=='1')
                       {   chess[i][j]='Q';
                           
                            break;
                                 
                                 }
                                 
                                
                                }
                                chess[i][j]='X';
                                }
                                
                                
                                 
                                 
                 for(i=0;i<4;i++){
                 
                 for(j=0;j<4;j++){
                      
                  printf("%c",chess[i][j]);               
                                 
                                 }
                                 printf("\n");
                                 }
getch();
return 0;
}

