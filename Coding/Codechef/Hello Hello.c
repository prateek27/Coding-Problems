#include<stdio.h>
#include<conio.h>

int main(){
    int t;  //Number of test cases
    float dcost;int mins,tplans ;   //Default cost , Mins and no of plans
          //validity in months, new call rate , vochuer cost 
    scanf("%d",&t);
    
    while(t){
             scanf("%f",&dcost);
             scanf("%d",&mins);
             scanf("%d",&tplans);
             
             
              
              int validity[tplans];
              float ncost[tplans];
              float vcost[tplans];
              float pmcost[tplans];
              
              int i;
              for(i=0;i<tplans;i++){
              scanf("%d%f%f",&validity[i],&ncost[i],&vcost[i]);
              pmcost[i]=   vcost[i]/validity[i] + (float)ncost[i]*mins;
              }     
              int index=0;float min;
              if(tplans>1){
              min=pmcost[0];
              for(i=0;i<tplans;i++){
              if(pmcost[i]<min)
              { min=pmcost[i];
               index=i;
               }}}
               else{
               min=pmcost[0];
               index=0;
               }
                float defaultcost=dcost*mins;
                
                
                int ans= min>defaultcost?0:(index+1);
                printf("%d\n",ans);               
               index=0;
               
            t--;
            
            }    
            
getch();
return 0;
}
            
            
            
            
