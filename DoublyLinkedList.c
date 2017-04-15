/* DOUBLY-LINKED LIST */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* structure definition */
struct nodeDLL
{
       int info; /* contains information */
       struct nodeDLL *next; /* contains address of next element in the list */
       struct nodeDLL *prev; /* contains address of previous element in the list */
};

typedef struct nodeDLL* NODEPTRDLL;

/* function prototypes */
void insertNodePos(NODEPTRDLL*, int, int);
void deleteNode(NODEPTRDLL*, int);
void displayDLL(NODEPTRDLL);
int countNode(NODEPTRDLL);
void insertAfter(NODEPTRDLL, int);
void createList(NODEPTRDLL*);

/* main */
int main(void)
{
    NODEPTRDLL list, secondList;
    int choice, pos, item;
    printf("Create a list.\n\n");
    createList(&list);
    do
    {
                      printf("\n-------------- MENU -------------\n");
                      printf("1. Insert an element into the list\n");
                      printf("2. Delete an element from the list\n");
                      printf("3. Display list\n");
                      printf("4. Exit\n");
                      printf("-------------------------------------");
                      
                      printf("\nEnter your choice (1 / 2 / 3 / 4): ");
                      scanf("%d", &choice);
                      switch(choice)
                      {
                                    case 1:    printf("\nEnter the position where the element is to be inserted: ");
                                               scanf("%d", &pos);
                                               printf("\nEnter the element to be inserted: ");
                                               scanf("%d", &item);
                                               insertNodePos(&list, item, pos);
                                               break;
                                                
                                    case 2:    printf("\nEnter the element to be deleted: ");
                                               scanf("%d", &item);
                                               deleteNode(&list, item);
                                               break;
                                                
                                    case 3:    printf("\nThe list contains: ");
				                               displayDLL(list);
                                               break;
                                                
                                    case 4:    printf("\nExiting program...\n");
				                               exit(0);
                                    
                                    default:   printf("\nInvalid choice!");
                      }
    } while(choice != 4);
    getch();
    return 0;
} /* end of main */

/* function to create a list */
void createList(NODEPTRDLL *plist)
{
     *plist = NULL; /* initialising list to empty state */
     NODEPTRDLL newNode, lastNode = *plist;
     int x;
     char choice;
     do
     {
          printf("\nEnter info.: ");
          scanf("%d", &x);
          newNode = malloc(sizeof(struct nodeDLL));
          newNode -> info = x;
          newNode -> next = NULL;
          newNode -> prev = lastNode;
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
void insertNodePos(NODEPTRDLL* plist, int x, int pos)
{
     int i;
     NODEPTRDLL newNode, p; 
     if(pos < 1 || pos > (countNode(*plist) + 1))
     {
            printf("\nInvalid position.\n");
            return;
     }
     if(pos == 1) /* insertion at first position */
     {
            newNode = malloc(sizeof(struct nodeDLL));
            newNode -> info = x;
            newNode -> next = *plist;
            newNode -> prev = NULL;
            *plist = newNode;
     }
     else /* insertion other than at first position */
     {
         for(p = *plist, i = 0; i < pos - 2; ++i)
               p = p -> next;
         insertAfter(p, x);
     }
}

/* function to insert a node immediately after the node being pointed to by p */
void insertAfter(NODEPTRDLL p, int x)
{
     NODEPTRDLL q;
     if(p == NULL)
     {
          printf("\nVoid insertion.");
          return;
     }
     q = malloc(sizeof(struct nodeDLL));
     q -> info = x;
     q -> next = p -> next;
     p -> next = q;
     if(q -> next != NULL)
          (q -> next) -> prev = q;
     q -> prev = p;    
}


/* function to delete a node containing a specific value */
void deleteNode(NODEPTRDLL* plist, int x)
{
     int flag = FALSE;
     NODEPTRDLL p = *plist, delNode;
     while(p != NULL)
     {
           if(p -> info == x)
           {
                flag = TRUE;
                delNode = p;
                if(p == *plist) /* element is found at first node */
                {
                     *plist = p -> next;
                     p = p -> next;
                     free(delNode);
                     continue;
                }
                else
                {
                    
                    if(p -> next == NULL) /* element is found at last node */
                    {
                         (p -> prev) -> next = NULL;
                         p = p -> next;
                         free(delNode);
                         continue;
                    }
                    else /* element is found at any node other than the first and last nodes */
                    {
                        (p -> prev) -> next = p -> next;
                        (p -> next) -> prev = p -> prev;
                        p = p -> next;
                        free(delNode);
                        continue;
                    }
                }
           }
           p = p -> next;
     }
     if(flag == FALSE)
             printf("\nElement not found in list.\n");
}             

/* function to display the list */
void displayDLL(NODEPTRDLL p)
{
     while(p != NULL)
     {
             printf("%d ", p -> info);
             p = p -> next;
     }
     printf("\n");
}

/* function to count the number of nodes in the list */
int countNode(NODEPTRDLL p)
{
    int count = 0;
    for( ; p != NULL; p = p -> next)
         count++;
    return count;
}
