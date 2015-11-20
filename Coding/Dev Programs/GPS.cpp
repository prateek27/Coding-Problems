#include<stdio.h>
#include<conio.h>


int main()
 {  float longitude;
    float latitude;
    int started=0;
    
    char info[80];
    puts("data=[");
    while(scanf("%f,%f,%79[^\n]",&latitude,&longitude,info)==3){
    if(started)
    printf(",\n");
    else
    started=1;
    printf("{latitude: %f, longitude: %f, info: '%s'},",latitude,longitude,info);
}
puts("\n]");
getch();
return 0;

}               
