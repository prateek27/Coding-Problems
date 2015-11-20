#include<iostream>
using namespace std;
int stack[5];
int top=-1;
void push(int stack[],int *x)
{  if(top==4) { cout<<"OverFlow"; }
   else stack[++top]=*x;
 }
int pop(int stack[]){
if(top==-1) {cout<<"UnderFlow"; return -1;}
return stack[top--];
}

void display(int stack[]){
for(int i=top;i>=0;i--) cout<<stack[i]<<endl;}

int main()
{
int x;
int choice;
cout<<"--OPERATIONS--"<<endl;
cout<<"1.Insertion   2.Pop  3.Display   4.Exit"<<endl;
cin>>choice;
while(choice){
switch(choice) {
case 1:cout<<"Enter the element to be inserted ";cin>>x;push(stack,&x);break;
case 2:cout<<"Popping ....  ";cout<<pop(stack);break;
case 3:cout<<"Elements of stack are ";display(stack);break;
default:cout<<"Invalid choice ";
}
cout<<"Enter your choice ";
cin>>choice; if(choice==4) break;
}
return 0;
}
