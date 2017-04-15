#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MAXSTACK 25
#define TRUE 1
#define FALSE 0

struct stack
{
       int expr[MAXSTACK];
       int top;
};

int empty(struct stack*); /* function prototype for empty; returns TRUE if stack is empty, FALSE otherwise */
void initStack(struct stack*); /* function prototype for initStack; initialises the stack to empty state */
void push(struct stack*, int); /* function prototype for push */
int pop(struct stack*); /* function prototype for pop */

int main(void)
{
    struct stack s;
    char postfix[MAXSTACK]; 
    int i = 0, popped1, popped2, temp;
    initStack(&s);
    printf("Enter a postfix expression: ");
    gets(postfix);
    for(i=0; i<strlen(postfix); i++)
    {
             if(postfix[i] == '+')
             {
                           popped2 = pop(&s);
                           popped1 = pop(&s);
                           temp = popped1 + popped2;
                           push(&s, temp);
                           continue;
             }
             if(postfix[i] == '-')
             {
                           popped2 = pop(&s);
                           popped1 = pop(&s);
                           temp = popped1 - popped2;
                           push(&s, temp);
                           continue;
             }
             if(postfix[i] == '*')
             {
                           popped2 = pop(&s);
                           popped1 = pop(&s);
                           temp = popped1 * popped2;
                           push(&s, temp);
                           continue;
             }
             if(postfix[i] == '/')
             {
                           popped2 = pop(&s);
                           popped1 = pop(&s);
                           temp = popped1 / popped2;
                           push(&s, temp);
                           continue;
             }
             if(postfix[i] == '^')
             {
                           popped2 = pop(&s);
                           popped1 = pop(&s);
                           temp = pow(popped1, popped2);
                           push(&s, temp);
                           continue;
             }
             else
             {
                 temp = postfix[i] - 48;
                 push(&s, temp);
             }
    }
    printf("\n%s = %d\n", postfix, pop(&s));
    getch();
    return 0;
}

/* function definition for empty */
int empty(struct stack *ps)
{
    if(ps->top == -1)
     return TRUE;
    else
     return FALSE;
}
     
/* function definition for initStack */
void initStack(struct stack *ps)
{
     ps->top = -1;
}

/* function definition for push */
void push(struct stack *ps, int c)
{
     if(ps->top == MAXSTACK-1)
     {
                printf("Overflow!");
     }
     else
     {
         ps->top = (ps->top)+1;
         ps->expr[ps->top] = c;
     }
}
/* function definition for pop */
int pop(struct stack *ps)
{
     int pitem;
     if(empty(ps))
      return FALSE;
     else
     {
         pitem = ps->expr[ps->top--];
         return pitem;
     }
}
