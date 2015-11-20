#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAXCOLS 80
#define TRUE 1
#define FALSE 0
struct stack{
    int top;
    double items[MAXCOLS];
    };
//List of Functions
double oper(int,double,double);
int isdigit(char);
double eval(char[]);
void push(struct stack *ps,int x);
double pop(struct stack *ps);

int main(){
char expr[MAXCOLS];int position=0;
while((expr[position++]=getchar())!='\n');
expr[--position]='\0';
printf("The Orignial Postfix Expression is : %s",expr);
printf("\n %f Ans ",eval(expr));
return 0;
}

//Create a stack

double eval(char expr[]){

int c,position;
double opnd1,opnd2,value;
struct stack opndstck;

opndstck.top=-1;
for(position=0;(c=expr[position])!='\0';position++)
    if(isdigit(c))                        //If it is number
        push(&opndstck,(double)(c-'0'));

      else   {             //If it is a operator
      opnd2=pop(&opndstck);
      opnd1=pop(&opndstck);
      value= oper(c,opnd1,opnd2);
      push(&opndstck,value);

      }

 return(pop(&opndstck));
}


int isdigit(char symb){
return(symb>='0'&&symb<='9');
}
double oper(int symb,double op1,double op2){
switch(symb){
case '+':return(op1+op2);
case '-': return(op1-op2);
case '*': return(op1*op2);
case '/': return(op1/op2);
case '$': return(pow(op1,op2));
default:printf(" Illegal Operation");
exit(1);
}}

void push(struct stack *ps,int x){
    if(ps->top==MAXCOLS-1){ printf("Stack Overflow !"); exit(1);  }

ps->top++ ;
ps->items[(ps->top)]=x;
}

double pop(struct stack *ps){
if(ps->top==-1){
    printf("Stack is empty");
    exit(1);
}

else
 return(ps->items[ps->top--]);

}



