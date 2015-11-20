#include<stdio.h>


//Program to Check whether a input expression is Right or Wrong

#define STACKSIZE 100

int main(){
struct stack{
int top;
int items[STACKSIZE];
};
struct stack s;
s.top=-1;                   //Intialize the top to -1
//EMPTY-----------------------------------------------
int isEmpty(struct stack *ps){
if(ps->top==-1)
    return 1;
else
    return 0;
}
//POP------------------------------------------------
char pop(struct stack *ps){
if(isEmpty(ps)){
 printf("STACK UNDERFLOW ");
 exit(1);
}
return(ps->items[ps->top--]);
}
//PUSH ----------------------------------------
void push(struct stack *ps,char x){
if(ps->top==STACKSIZE-1){
    printf("Stack Overflow ");

    exit(1);
}
else
    ps->items[++ps->top]=x;
    return ;
}
//Program to INput a String and Check its validity -----------------------------
char exp[100];
int valid = 1;
printf("Enter an Expression :");
scanf("%s",&exp);
int i=0;
while(exp[i]!='\0'){
       // printf(" %c",exp[i]);
    if(exp[i]=='('){
        push(&s,exp[i]);
       // printf("I pushed %s\n",exp);
       }
    if(exp[i]==')'){
            if(isEmpty(&s))
             valid =0;
            else{
                char k=pop(&s);
               // printf("I popped %c\n",k);
            }
         } //end if
         i++;
    }        //end while

if(!isEmpty(&s))                //TO check if Some Left Braces are left .
        valid=0;

if(valid)
    printf("String is Valid ");
else
     printf("Invalid String");

return 0;
}
