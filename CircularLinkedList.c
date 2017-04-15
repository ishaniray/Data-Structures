/* CIRCULAR LINKED LIST */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* structure definition */
struct node
{
       int info; /* contains information */
       struct node *next; /* contains address of next element in the list */
};

typedef struct node* NODEPTR;

/* function prototypes */
void createList(NODEPTR*);
void insertAfterx(NODEPTR*, NODEPTR, int, int);
void insertAfter(NODEPTR*, NODEPTR, int);
void deleteNodex(NODEPTR*, int);
void deleteFirst(NODEPTR*);
void deleteAfter(NODEPTR, NODEPTR*);
void displayList(NODEPTR);
int countNode(NODEPTR);
void concatList(NODEPTR*, NODEPTR*);

/* main */
int main(void)
{
	NODEPTR list, secondList;
    int choice, item, x;
    printf("Create a list.\n\n");
    createList(&list);
    do
    {
                      printf("\n---------------------------- MENU ---------------------------\n");
                      printf("1. Insert an element into the list after a particular element\n");
                      printf("2. Delete a specific element from the list\n");
                      printf("3. Display list\n");
                      printf("4. Count the number of elements in the list\n");
                      printf("5. Create another list and concatenate the two lists\n");
                      printf("6. Exit\n");
                      printf("-------------------------------------------------------------");
                      printf("\nEnter your choice (1 / 2 / 3 / 4 / 5 / 6): ");
                      scanf("%d", &choice);
                      switch(choice)
                      {
                      	case 1:		printf("\nEnter the item to be inserted: ");
     								scanf("%d", &item);
     								printf("\nEnter the value of the element after which you want to enter %d: ", item);
     								scanf("%d", &x);
     								insertAfterx(&list, list, x, item);
                                    break;
                                    
                        case 2:		printf("\nEnter the element to be deleted: ");
                                    scanf("%d", &item);
                                    deleteNodex(&list, item);
                                    break;

                        case 3:     printf("\nThe list contains: ");
									displayList(list);
									printf("\n");
                                    break;
                                                
                        case 4:     printf("\n\nThe number of elements in the list is: %d\n", countNode(list));
                                    break;
                                    
                        case 5:     printf("\n\nCreate another list.\n");
                                    createList(&secondList);
                                    concatList(&list, &secondList);
                                    break;
                                                
                        case 6:     printf("\nExiting program...\n");
									exit(0);
                                    
                        default:    printf("\nInvalid choice!\n");
                    }
    } while(choice != 6);
    getch();
	return 0;
} /* end of main */

/* function to create a list */
void createList(NODEPTR *plist)
{
     *plist = NULL; /* initialising list to empty state */
	 NODEPTR newNode, lastNode;
     int x;
     char choice;
     do
     {
          printf("\nEnter info.: ");
          scanf("%d", &x);
          newNode = malloc(sizeof(struct node));
          newNode -> info = x;
          if(*plist == NULL) /* list is empty */
          {
                    *plist = newNode;
                    newNode -> next = *plist;
          }
          else
          {
              newNode -> next = lastNode -> next;
              lastNode -> next = newNode;
              *plist = newNode;
          }
          lastNode = newNode;
          printf("\nContinue? (y / Y)\n");
          scanf(" %c", &choice);
     } while(choice == 'y' || choice == 'Y');
}

/* function to insert a node after a node containing a specific value */
void insertAfterx(NODEPTR *plist, NODEPTR p, int x, int item)
{
     if(p == NULL)
     {
          printf("\nVoid operation. List is empty.\n");
          return;
     }
     while(p -> info != x && p -> next != *plist)
             p = p -> next;
     if(p -> next == *plist && p -> info != x)
     {
     	printf("\nElement not found in the list.\n");
     	return;
     }
     insertAfter(plist, p, item);
}

/* function to insert a node immediately after the node being pointed to by p */
void insertAfter(NODEPTR *plist, NODEPTR p, int x)
{
     NODEPTR q;
     if(p == NULL)
     {
          printf("\nVoid insertion.\n");
          return;
     }
     q = malloc(sizeof(struct node));
     q -> info = x;
     q -> next = p -> next;
     p -> next = q;
     if(p == *plist)
     	*plist = q;
}

/* function to delete a node containing a specific value */
void deleteNodex(NODEPTR *plist, int x)
{
     NODEPTR p, prevNode; /* p points to the node to be deleted; prevNode points to the node immediately before the node pointed to by p */
     int flag = 0;
     p = (*plist) -> next;
     prevNode = *plist;
     if(p -> info == x) /* x is found in the first node */
     {
     	 flag = 1;
		 p = p -> next;
         deleteFirst(plist);
     }
     if(*plist == NULL)
     	return;
     prevNode = p;
     p = p -> next;
     while(p != (*plist) -> next)
     {
     	if(p -> info == x)
     	{
     		flag = 1;
         	p = p -> next;
			deleteAfter(prevNode, plist);
			if(*plist == prevNode)
				return;
			continue;
        }
        prevNode = p;
        p = p -> next;
    }
     if(flag == 0 && p == (*plist) -> next)
     {
          printf("\nElement not found in list.\n");
          return;
     }
 }
 
 void deleteFirst(NODEPTR *plist)
{
     NODEPTR delNode; /* points to the node to be deleted */
     if(*plist == NULL) /* empty list */
     {
               printf("\nEmpty list, deletion not possible.\n");
               return;
     }
     delNode = (*plist) -> next;
     (*plist) -> next = delNode -> next;
     if((*plist) -> next == delNode)
     	*plist = NULL;
     free(delNode);
}

/* function to delete the node immediately succeeding the node being pointed to by p */
void deleteAfter(NODEPTR p, NODEPTR *plist)
{
     NODEPTR q;
     if(p == NULL || p -> next == NULL)
     {
          printf("\nVoid deletion.\n");
          return;
     }
     q = p -> next;
     p -> next = q -> next;
     if(q == *plist)
     	*plist = p;
     free(q);
}

/* function to display the list */
void displayList(NODEPTR list)
{
	NODEPTR p;
	if(list == NULL)
	{
		printf("\nList is empty.\n");
		return;
	}
	p = list -> next;
	while(p != list)
	{
		printf("%d ", p -> info);
		p = p -> next;
	}
	printf("%d ", list -> info);
}

/* function to count the number of nodes in the list */
int countNode(NODEPTR p)
{
	int count = 1;
	NODEPTR q = p;
	while(q -> next != p)
	{
		count++;
		q = q -> next;
	}
	return count;
}

/* function to concatenate two lists */
void concatList(NODEPTR *plist1, NODEPTR *plist2)
{
	NODEPTR temp;
	if(*plist2 == NULL) /* 2nd list is empty */
		return;
	if(*plist1 == NULL) /* 1st list is empty */
	{
		*plist1 = *plist2;
		return;
	}
	temp = (*plist1) -> next;
	(*plist1) -> next = (*plist2) -> next;
	(*plist2) -> next = temp;
	*plist1 = *plist2;
}
