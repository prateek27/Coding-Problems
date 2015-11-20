#include<iostream>
#include<string>
#include<cstdio>
#include<conio.h>
#include<cstring>
#include<windows.h>
#include<time.h>
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
using namespace std;
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
COORD coord={0,0};
void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
char maze[100][100];
int x,y;
int can_move(int a,int b){
    if(a>=x||b>=y||a<0||b<0||maze[a][b]=='#')
        return 0;
    return 1;
}
void maze_solve(int a,int b,int current_direction){
    delay(1000);
    if(a==x-2&&b==y-1){
        printf("   Maze Solved! :D");
        gotoxy(0,y+5);
        exit(0);
    }
    if(current_direction==1)
        goto label1;
    if(can_move(a+1,b)){
        gotoxy(b,a+1+2);
        printf("*");
        maze_solve(a+1,b,3);
        printf("\b");
    } label1:
    if(current_direction==3)
        goto label2;
    if(can_move(a-1,b)){
        gotoxy(b,a-1+2);
        printf("*");
        maze_solve(a-1,b,1);
        printf("\b");
    } label2:
    if(current_direction==4)
        goto label3;
    if(can_move(a,b+1)){
        gotoxy(b+1,a+2);
        printf("*");
        maze_solve(a,b+1,2);
        printf("\b");
    } label3:
    if(current_direction==2)
        goto label4;
    if(can_move(a,b-1)){
        gotoxy(b-1,a+2);
        printf("*");
        maze_solve(a,b-1,4);
        printf("\b");
    } label4:
        int xxx;
}
void input_maze(){
    for(int i=0;i<x;i++)
        cin.getline(maze[i],100,'\n');
}
int main(void){
    printf("Enter the dimensions of the maze:");
    si(x);si(y);
    printf("Enter the maze..use # for wall and space for blank area:\n");
    fflush(stdin);
    input_maze();
    gotoxy(0,3);
    printf("*");
    maze_solve(1,0,2);
}
