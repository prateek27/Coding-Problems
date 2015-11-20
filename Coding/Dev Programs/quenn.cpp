#include<stdio.h>
#include<conio.h>
int main()
{
    int i , j;
    char chess[4][4];
                  int a[4][4]={0,1,1,0,
                               1,0,1,1,
                               1,1,1,0,
                               1,1,0,1};
                 for(i=0;i<4;i++){
                 for(j=0;j<4;j++){
                     
                     
                                 printf("%d ",a[i][j]);
                                 if(a[i][j]==0)
                                 chess[i][j]='Q';
                                 
                                 else
                                 chess[i][j]=a[i][j];
                                 
                                  }
                                  printf("\n");
                                  }
                                  
                                   for(i=0;i<4;i++){
                                    for(j=0;j<4;j++){
                                                     printf("%c ",chess[i][j]);
                                                     }
                                                     printf("\n");
                                                     }
                                  getch();
                                  return 0;
                                  }
