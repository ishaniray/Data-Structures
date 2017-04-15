#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAXSTACK 25
#define TRUE 1
#define FALSE 0

struct stack
{
       char expr[MAXSTACK];
       int top;
};

int empty(struct stack*); /* function prototype for empty; returns TRUE if stack is empty, FALSE otherwise */
void initStack(struct stack*); /* function prototype for initStack; initialises the stack to empty state */
void push(struct stack*, char); /* function prototype for push */
char pop(struct stack*); /* function prototype for pop */
int priorityCheck(char, char); /* function prototype for priorityCheck; returns TRUE if incoming operator's precedence is greater than stacktop operator, FALSE otherwise */

int main(void)
{
    struct stack s;
    int i=0, j=0;
    char infix[MAXSTACK], postfix[MAXSTACK], popped;
    initStack(&s);
    printf("Enter an infix expression: ");
    gets(infix);
    while(i<strlen(infix))
    {
             if(infix[i] == '(')
             {
                         push(&s, infix[i]);
                         i++;
                         continue;
             }
             if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i]=='^')
             {
                         popped = pop(&s);
                         if(popped == 'F')
                         {
                                   push(&s, infix[i]);
                                   i++;
                                   continue;
                         }
                         if(popped == '(')
                         {
                                   push(&s, popped);
                                   push(&s, infix[i]);
                                   i++;
                                   continue;
                         }
                         if(priorityCheck(infix[i],popped))
                         {
                                   push(&s, popped);
                                   push(&s, infix[i]);
                                   i++;
                                   continue;
                         }
                         else
                         {
                             postfix[j] = popped;
                             j++;
                             continue;
                         }
             }
             if(infix[i] == ')')
             {
                         while((popped = pop(&s))!='(')
                         {
                             postfix[j] = popped;
                             j++;
                         }
                         i++;
             }
             else
             {
                 postfix[j] = infix[i];
                 j++;
				 i++;
             }
    }
    while((popped = pop(&s))!='F')
    {
    	postfix[j] = popped;
        j++;
    }
    postfix[j] = '\0';
    printf("\nThe equivalent postfix expression is: %s\n", postfix);
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
void push(struct stack *ps, char c)
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
char pop(struct stack *ps)
{
     char pitem;
     if(empty(ps))
      return 'F';
     else
     {
         pitem = ps->expr[ps->top--];
         return pitem;
     }
}

/* function to check priority of incoming operator */
int priorityCheck(char incoming, char stacktop)
{
    if(incoming == '^')
     return TRUE;
    else
    {
        if(incoming == '+' || incoming == '-')
         return FALSE;
        else
        {
            if(stacktop == '*' || stacktop == '/')
             return FALSE;
            return TRUE;
        }
    }
}
              
    
