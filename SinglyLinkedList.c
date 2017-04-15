/* SINGLY-LINKED LIST */

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
void insertNodePos(NODEPTR*, int, int);
void deleteNodePos(NODEPTR*, int);
void insertAfter(NODEPTR, int);
void deleteFirst(NODEPTR*);
void deleteAfter(NODEPTR);
void deleteNodex(NODEPTR*, int);
void insertAfterx(NODEPTR);
int countNode(NODEPTR);
void displayList(NODEPTR);
void concatList(NODEPTR*, NODEPTR*);
void searchx(NODEPTR, int);
void reverseList(NODEPTR*);

/* main */
int main(void)
{
    NODEPTR list, secondList;
    int choice1, pos, item;
    char choice2;
    printf("Create a list.\n\n");
    createList(&list);
    do
    {
                      printf("\n------------------------ MENU -----------------------\n");
                      printf("1. Insert an element into the list\n");
                      printf("2. Delete an element from the list\n");
                      printf("3. Display list\n");
                      printf("4. Count the number of elements in the list\n");
                      printf("5. Search for an element in the list\n");
                      printf("6. Reverse the list\n");
                      printf("7. Create another list and concatenate the two lists\n");
                      printf("8. Exit\n");
                      printf("-----------------------------------------------------");
                      
                      printf("\nEnter your choice (1 / 2 / 3 / 4 / 5 / 6 / 7 / 8): ");
                      scanf("%d", &choice1);
                      switch(choice1)
                      {
                                    case 1:     printf("\nA. Insert at a specific position.");
                                                printf("\nB. Insert after a specific value.");
                                                printf("\nEnter your choice (A / B): ");
                                                scanf(" %c", &choice2);
                                                switch(choice2)
                                                {
                                                               case 'A':     printf("\nEnter the position where the element is to be inserted: ");
                                                                             scanf("%d", &pos);
                                                                             printf("\nEnter the element to be inserted: ");
                                                                             scanf("%d", &item);
                                                                             insertNodePos(&list, item, pos);
                                                                             break;
                                                                             
                                                               case 'B':     insertAfterx(list);
                                                                             break;
                                                                             
                                                               default:      printf("\nInvalid choice!");
                                                }
                                                break;
                                                
                                    case 2:     printf("\nA. Delete from a specific position.");
                                                printf("\nB. Delete a particular value.");
                                                printf("\nEnter your choice (A / B): ");
                                                scanf(" %c", &choice2);
                                                switch(choice2)
                                                {
                                                               case 'A':     printf("\nEnter the position from where an element is to be deleted: ");
                                                                             scanf("%d", &pos);
                                                                             deleteNodePos(&list, pos);
                                                                             break;
                                                                             
                                                               case 'B':     printf("\nEnter the element to be deleted: ");
                                                                             scanf("%d", &item);
                                                                             deleteNodex(&list, item);
                                                                             break;
                                                                             
                                                               default:      printf("\nInvalid choice!");
                                                }
                                                break;
                                                
                                    case 3:     printf("\nThe list contains: ");
												displayList(list);
                                                break;
                                                
                                    case 4:     printf("\n\nThe number of elements in the list is: %d\n", countNode(list));
                                                break;
                                                
                                    case 5:     printf("\n\nEnter the element to search for: ");
                                                scanf("%d", &item);
                                                searchx(list, item);
                                                break;
                                                
                                    case 6:     reverseList(&list);
                                                break;
                                                
                                    case 7:     printf("\n\nCreate another list.\n");
                                                createList(&secondList);
                                                concatList(&list, &secondList);
                                                break;
                                                
                                    case 8:     printf("\nExiting program...\n");
												exit(0);
                                    
                                    default:    printf("\nInvalid choice!");
                      }
    } while(choice1 != 8);
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
          newNode -> next = NULL;
          if(*plist == NULL) /* list is empty */
                    *plist = newNode;
          else
              lastNode -> next = newNode;
          printf("\nContinue? (y / Y)\n");
          scanf(" %c", &choice);
          lastNode = newNode;
     } while(choice == 'y' || choice == 'Y');
}

/* function to insert a node at any position */
void insertNodePos(NODEPTR *plist, int x, int pos)
{
     int i;
     NODEPTR newNode, p;
     if(pos < 1 || pos > (countNode(*plist) + 1))
     {
            printf("\nInvalid position.\n");
            return;
     }
     if(pos == 1) /* insertion at first position */
     {
            newNode = malloc(sizeof(struct node));
            newNode -> info = x;
            newNode -> next = *plist;
            *plist = newNode;
     }
     else /* insertion other than at first position */
     {
         for(p = *plist, i = 0; i < pos - 2; ++i)
               p = p -> next;
         insertAfter(p, x);
     }
}

/* function to delete a node from any position */
void deleteNodePos(NODEPTR *plist, int pos)
{
     NODEPTR p;
     int i;
     if(pos < 1 || pos > countNode(*plist))
     {
            printf("\nInvalid position.\n");
            return;
     }
     if(pos == 1)
            deleteFirst(plist);
     else
     {
         for(p = *plist, i = 1; i < pos - 1; ++i)
               p = p -> next;
         deleteAfter(p);
     }
}

/* function to insert a node immediately after the node being pointed to by p */
void insertAfter(NODEPTR p, int x)
{
     NODEPTR q;
     if(p == NULL)
     {
          printf("\nVoid insertion.");
          return;
     }
     q = malloc(sizeof(struct node));
     q -> info = x;
     q -> next = p -> next;
     p -> next = q;
}

/* function to delete the first node in a list */
void deleteFirst(NODEPTR *plist)
{
     NODEPTR delNode; /* points to the node to be deleted */
     if(*plist == NULL) /* empty list */
     {
               printf("\nEmpty list, deletion not possible.");
               return;
     }
     delNode = *plist;
     *plist = delNode -> next;
     free(delNode);
}

/* function to delete the node immediately succeeding the node being pointed to by p */
void deleteAfter(NODEPTR p)
{
     NODEPTR q;
     if(p == NULL || p -> next == NULL)
     {
          printf("\nVoid deletion.");
          return;
     }
     q = p -> next;
     p -> next = q -> next;
     free(q);
}


/* function to delete a node containing a specific value */
void deleteNodex(NODEPTR *plist, int x)
{
     NODEPTR p, prevNode; /* p points to the node to be deleted; prevNode points to the node immediately before the node pointed to by p */
     int flag = 0;
     p = *plist;
     prevNode = NULL;
     while(p != NULL)
     {
     	if(p -> info == x)
     	{
     		flag = 1;
     		if(p == *plist) /* x is found in the first node */
     		{
     			p = p -> next;
          		deleteFirst(plist);
          		continue;
          	}
     		else
     		{
         		 p = p -> next;
				 deleteAfter(prevNode);
				 continue;
			}
        }
        prevNode = p;
        p = p -> next;
    }
     if(p == NULL && flag == 0)
     {
          printf("\nElement not found in list.\n");
          return;
     }
 }

/* function to insert a node after a node containing a specific value */
void insertAfterx(NODEPTR p)
{
     int x, item;
     if(p == NULL)
     {
          printf("\nVoid operation. List is empty.\n");
          return;
     }
     printf("\nEnter the item to be inserted: ");
     scanf("%d", &item);
     printf("\nEnter the value of the element after which you want to enter %d: ", item);
     scanf("%d", &x);
     while(p -> info != x && p -> next != NULL)
             p = p -> next;
     if(p -> next == NULL)
     {
     	printf("\nElement not found in the list.\n");
     	return;
     }
     insertAfter(p, item);
}

/* function to count the number of nodes in the list */
int countNode(NODEPTR p)
{
    int count = 0;
    for( ; p != NULL; p = p -> next)
         count++;
    return count;
}

/* function to display the list */
void displayList(NODEPTR p)
{
     while(p != NULL)
     {
             printf("%d ", p -> info);
             p = p -> next;
     }
     printf("\n");
}

/* function to concatenate two lists */
void concatList(NODEPTR *l1, NODEPTR *l2)
{
     NODEPTR p;
     if(*l2 == NULL) /* Case 1: 2nd list is empty */
            return;
     if(*l1 == NULL) /* Case 2: 1st list is empty */
     {
            *l1 = *l2;
            return;
     }
     for(p = *l1; p -> next != NULL; p = p -> next)
     ;
     p -> next = *l2;
}

/* function to search for an element in the list */
void searchx(NODEPTR p, int x)
{
     int i = 1;
     while(p != NULL)
     {
             if(p -> info == x)
             {
                  printf("\n%d was found at position %d.\n", x, i);
                  return;
             }
             i++;
             p = p -> next;
     }
     printf("\n%d was not found.", x);
}

/* function to reverse the list */
void reverseList(NODEPTR *plist)
{
     NODEPTR prevNode = NULL, currNode = *plist, nextNode;
     while(currNode != NULL)
     {
            nextNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
     }
     *plist = prevNode;
}
