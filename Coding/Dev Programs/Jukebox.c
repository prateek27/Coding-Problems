#include<stdio.h>
#include<conio.h> 
#include<string.h>

char tracks[][80]={"Tum hi ho ", "Sadi gali aaja ve ", "Meri Aashiqi ","Jeene laga hoon",};

void find_track(char song[]){
     int i;
     for(i=0;i<5;i++)
     {
                     if(strstr(tracks[i],song))
                     printf("Track is '%s' at position %i",tracks[i],i+1);
                     }
                     }
int main(){
    char search_for[80];
    printf("/n Enter search track : ");
    fgets(search_for,80,stdin);
    find_track(search_for);

getch();
return 0;

}
    
