
// convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Stack
{
    int top;
    unsigned int capacity;
    int* array;
} Stack;

Stack *createStack(unsigned int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if(!stack)
        return NULL;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity *sizeof(int));
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top ==-1;
}

char peek (Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int prec(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else 
        return -1;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int infixtopostfix(char* exp)
{
    int i,k,j;
    int l=strlen(exp);

    Stack *stack = createStack(l);

    if(!stack)
    {
        return -1;
    }

    for (i = 0, k = -1; exp[i] != '\0'; i++)
    {
        if(isOperand(exp[i]))
            exp[++k]=exp[i];
        else if (exp[i]=='(')
            push(stack,exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;           
            else
                pop(stack);
        }
        else
        {
            while(!isEmpty(stack) && (prec(exp[i])<=prec(peek(stack))))
            {
                exp[++k]=pop(stack);
            }
            push(stack,exp[i]);
        }
    }
    while(!isEmpty(stack))
        exp[++k]=pop(stack);
    exp[++k]='\0';
    printf("%s ",exp);

}


int main()
{
    char exp[] = "a+(b*c-(d/e^f)*g)*h";
    infixtopostfix(exp);
    return 0;
}

//= "a+b*(c^d-e)^(f+g*h)-i";