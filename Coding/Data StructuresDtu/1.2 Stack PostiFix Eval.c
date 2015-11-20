///To evaluate a postfix expression
#include<stdio.h>
#include<math.h>
#include<stdlib.h>                 //For EXIT Function
#define MAXSIZE 100


//--------------------------------------------------LIST OF FUNCTIONS;
double operate(double op1,double op2,char symbol);
int isDigit(char symbol);
double eval(char exp[]);



//---------------------------------------------------------MAIN FUNCTION
int main(){
char exp[MAXSIZE];
int index=0;
printf("Enter a Postfix Expression : ");
while((exp[index++]=getchar())!='\n');          //NOTE
exp[--index]='\0';
printf("The Origianl String is %s \n",exp);
printf("The Evaluated Postfix expression value is :%f \n",eval(exp));
return 0;
}
//-----------------------------------------------------------------------------------STACK AND ITS METHODS
struct stack{
int top;
char items[MAXSIZE];
};              //Put colon here too .

int isEmpty(struct stack *ps){  //----------------------------EMPTY METHOD
if(ps->top==-1)
    return 1;
else
    return 0;
}
char pop(struct stack *ps){   //-------------------------------POP METHOD
if(isEmpty(ps)){
 printf("STACK UNDERFLOW ");
 exit(1);
}
return(ps->items[ps->top--]);
}
void push(struct stack *ps,char x){      //--------------------PUSH METHOD
if(ps->top==MAXSIZE-1){
    printf("Stack Overflow ");

    exit(1);
}
else
    ps->items[++ps->top]=x;
    return ;
}
//--------------------------------------------------------------------------------------EVALUATING POSTFIX
double eval(char exp[]){
double operand1,operand2,value;
int i;
struct stack operandStack;
operandStack.top=-1;
char c;
for(i=0;(c=exp[i])!='\0';i++){
if(isDigit(c)){
push(&operandStack,(double)(c-'0'));      //Convert char into int and Push 'em in stack.
}
else{
    operand2=pop(&operandStack);
    operand1=pop(&operandStack);
    value =  operate(operand1,operand2,c);
    push(&operandStack,value);
    }
} //end for
return(pop(&operandStack));
}

int isDigit(char symbol){  //------------------------------CHECKING FOR INTEGER BW 0-9
return (symbol>='0'&&symbol<='9');
}

double operate(double op1,double op2,char symbol) //----------------CALCUATING THE VALUE USING VARIOUS OPERATIONS
{
    switch(symbol){
        case '+':return (op1+op2);
        case '-':return (op1-op2);
        case '*':return (op1*op2);
        case '/':return (op1/op2);
        case '^':return(pow(op1,op2));
        default:printf("Illegal Operation");
        exit(1);
    }
}
