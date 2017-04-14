/* STACK using SINGLY-LINKED LIST */
/* Push and Pop operations happen in constant time */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* structure definition */
struct node
{
       int info; /* contains information */
       struct node *next; /* contains address of previous element in the 'stack' */
};

typedef struct node* NODEPTR;

/* function prototypes */
void push(NODEPTR*, int, int*);
void pop(NODEPTR*, int*, int*);

/* main */
int main(void)
{
    NODEPTR stack = NULL; /* initialising stack to empty state */
    int underflow, overflow, popped, choice, x;
    do
    {
		printf("\n----------- MENU -------------\n");
        	printf("\n 1. PUSH    2. POP    3. EXIT\n");
       	        printf("\n------------------------------\n");
                printf("\nEnter your choice (1 / 2 / 3): ");
                scanf("%d", &choice);
		switch(choice)
		{
			case 1: 	printf("\nEnter the element to push: ");
					scanf("%d", &x);
					push(&stack, x, &overflow); /* function call to push */
					if(overflow) /*check for overflow*/
				        	printf("\nOverflow.\n");
					else
						printf("\n%d was pushed successfully to stack.\n", x);
					break;
					
			case 2: 	pop(&stack, &underflow, &popped);/* function call to pop */
					if(underflow) /*check for underflow*/
						printf ("\nUnderflow.\n");
					else
						printf("\nPopped element is %d.\n", popped);
					break;
					
			case 3: 	printf("\nExiting program...\n");
						break;
			
			default:	printf("\nInvalid choice. Try again.\n");
		}
    } while(choice != 3);
    getch();
    return 0;
} /* end of main */

/* function to push an element into the stack */
void push(NODEPTR *pstack, int x, int *overflow)
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL) /* malloc is unable to create space */
	{
		*overflow = TRUE;
		return;
	}
	*overflow = FALSE;
	newNode -> info = x;
	newNode -> next = *pstack;
	*pstack = newNode;
}

/* function to pop an element from the stack */
void pop(NODEPTR *pstack, int *underflow, int *pitem)
{
	if(*pstack == NULL) /* stack is empty */
	{
		*underflow = TRUE;
		return;
	}
	*underflow = FALSE;
	NODEPTR delNode;
	delNode = *pstack;
	*pstack = delNode -> next;
	*pitem = delNode -> info;
	free(delNode);
}
