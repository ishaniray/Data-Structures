/* QUEUE using CIRCULAR LINKED LIST */
/* Enqueue and Dequeue operations happen in constant time */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* structure definition */
struct node
{
       int info; /* contains information */
       struct node *next; /* contains address of next element in the 'queue', except the last node, which contains address of first element in the queue*/
};

typedef struct node* NODEPTR;

/* function prototypes */
void enqueue(NODEPTR*, int, int*);
void dequeue(NODEPTR*, int*, int*);

/* main */
int main(void)
{
	NODEPTR queue = NULL; /* initialising queue to empty state */
    int underflow, overflow, dequeued, choice, x;
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1. ENQUEUE    2. DEQUEUE    3. EXIT\n");
        printf("\n------------------------------\n");
        printf("\nEnter your choice (1 / 2 / 3): ");
        scanf("%d", &choice);
		switch(choice)
		{
			case 1: 	printf("\nEnter the element to enqueue: ");
						scanf("%d", &x);
						enqueue(&queue, x, &overflow); /* function call to enqueue */
						if(overflow) /*check for overflow*/
					   		printf("\nOverflow.\n");
						else
					  	 	printf("\n%d was enqueued successfully to queue.\n", x);
						break;
					
			case 2: 	dequeue(&queue, &dequeued, &underflow); /* function call to dequeue */
						if(underflow) /* check for underflow */
						   printf ("\nUnderflow.\n");
						else
					   		printf("\nDequeued element is %d.\n", dequeued);
						break;
					
			case 3: 	printf("\nExiting program...\n");
						break;
			
			default:	printf("\nInvalid choice. Try again.\n");
		}
	} while(choice != 3);
	getch();
	return 0;
} /* end of main */

/* function to insert an element into the queue */
void enqueue(NODEPTR *pq, int x, int *overflow)
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
	if(*pq == NULL) /* queue is empty */
		newNode -> next = newNode;
	else
	{
		newNode -> next = (*pq) -> next;
		(*pq) -> next = newNode;
	} /* insertion at beginning */
	*pq = newNode; /* insertion at the end */
}

/* function to delete an element from the queue */
void dequeue(NODEPTR *pq, int *x, int *underflow)
{
	NODEPTR delNode;
	if(*pq == NULL) /* queue is empty */
	{
		*underflow = TRUE;
		return;
	}
	*underflow = FALSE;
	if(*pq == (*pq) -> next) /* queue has one element */
	{
		*x = (*pq) -> info;
		free(*pq);
		*pq = NULL;
	}
	else
	{
		delNode = (*pq) -> next;
		(*pq) -> next = delNode -> next;
		*x = delNode -> info;
		free(delNode);
	}
}
