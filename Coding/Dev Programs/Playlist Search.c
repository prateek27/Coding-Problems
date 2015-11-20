#include<stdio.h>
#include<string.h>

void find_track(char song[50]);
char track[][50]={"Tum Hi Ho","Sun Rha Hai Na Tu ","Meri Aashiqi ","Milne Hai Mujhse Aayi "};
int main()
{ int temp=0;
    char temo;
    char search_song[50]; 
   char choice='y';
    
  
    while(choice=='y'||choice=='Y'){
    printf("Enter the track: ");
    scanf("%49s",&search_song);
    find_track(search_song);
    printf("\nWant to search more ?");
    scanf("%c %c",&temo,&choice);
}
     
        


 getch();
 return 0;   
}

void find_track(char song[50])
  {  int i,var;
     
     for(i=0;i<5;i++)
     {               
                     if(strstr(track[i],song)){
                     printf("Track is %s at positon %i",track[i],i+1);var=0;
                     break;
                     }
                     else
                     var=1;    
                     }
           if(var)
            printf("Not found !");    
                
     }

                     
                     
  
    
    
