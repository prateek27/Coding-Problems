#include<stdio.h>


//Program to Check whether a input expression is Right or Wrong and Print Contents of Stack at each time

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
int valid = 1;int j;
printf("Enter an Expression :");
scanf("%s",&exp);
int i=0;
while(exp[i]!='\0'){
       // printf(" %c",exp[i]);
    if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
        push(&s,exp[i]);

       }
    if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty(&s))
             valid =0;
            else{
                //   printf("%c I am at the top ",s.items[s.top]);

                    switch(exp[i]){
                    case ')': if(s.items[s.top]=='(')  pop(&s);break;
                    case '}': if(s.items[s.top]=='{')  pop(&s);break;
                    case ']': if(s.items[s.top]=='[')  pop(&s);break;
                    default: valid=0;

                    }


            }}
          //end if
           for(j=0;j<=s.top;j++){                  //FOR LOOP TO PRINT THE CURRENT STACK
           printf("%c ",s.items[j]);
           }
           printf("\n");
         i++;
        }    //end while

if(!isEmpty(&s))                //TO check if Some Left Braces are left .
        valid=0;

if(valid)
    printf("String is Valid ");
else
     printf("Invalid String");

return 0;
}
