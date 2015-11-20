#include<stdio.h>
#include<conio.h>

int main(){
    
    int t,triangles=0;
    scanf("%d",&t);
    int x1,x2,x3,y1,y2,y3,side1,side2,side3;
    while(t){
            
             scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
             side1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
             side2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
             side3=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
             
             if(side1==side2+side3||side2==side1+side3||side3==side2+side1)
             {
              triangles++;
             }
             t--;
            
             }
             printf("%d",triangles);
             
getch();
return 0;
}
             
