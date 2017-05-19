/* This program performs Radix (Linear) Sort in ascending order on an array of integers, using Circular Linked-Lists */
/* This definition of Radix Sort is adaptive */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* structure definition */
struct node
{
       int val;             /* information contained in node */
       struct node* next;  /* address of next node */
};

typedef struct node* NODEPTR;

/* function prototypes */
void radSort(int*, int); 
int maxKeyLength(int*, int, int*);
void insertLast(NODEPTR*, int);
int deleteFirst(NODEPTR*);

/* main */
int main(void)
{
    int n, *a, i;
    printf("How many numbers do you wish to sort?\n");
    scanf("%d", &n);
    a = malloc(n * sizeof(int));    /* creating an integer array of size n, dynamically */
    printf("\n\nEnter %d numbers:\n", n);
    for(i = 0; i < n; ++i)
          scanf("%d", &a[i]);         /* scanning in values from the user and populating the array */
    printf("\n\nList of numbers as entered by you: ");
    for(i = 0; i < n; ++i)
          printf("%d ", a[i]);
    printf("\n");
    radSort(a, n); /* function call to radSort */
    printf("\n\nFinal sorted list: ");
    for(i = 0; i < n; ++i)
          printf("%d ", a[i]);
    getch();
    return 0;
} /* end of main */

/* function to perform Radix Sort on an array of integers */
void radSort(int *a, int n)
{
     int flag = 0; /* status variable indicating that the initial array is sorted */
     int i, j, k, l, temp, mkl = maxKeyLength(a, n, &flag); /* maxKeyLength, apart from its primary operation, verifies whether or not the input array is sorted and changes flag's value accordingly */
     if(flag == 0) /* input array is sorted, as verified by maxKeyLength */
     {
             printf("\n\nList is already sorted. ");
             getch();
             exit(0);         /* sorting algorithm is not executed on an already-sorted list, thereby making the program adaptive */
     }
     /* else */
     NODEPTR p[10]; /* array of pointers; pointers are external pointers to lists; each list corresponds to the digits 0 - 9 respectively */
     for(i = 0; i < 10; ++i)
           p[i] = NULL;     /* initialising lists to null (empty lists) */
     for(k = 0; k < mkl; ++k)  /* outer loop runs for as many times as there are digits in the greatest value of the list */
     {
           j = 0; /* variable to keep track of a's index; initialised to 0 */
           for(i = 0; i < n; ++i)       /* loop runs for each element in the list */
           {
                 temp = a[i];
                 /* extraction of relevant digit */
                 for(l = 0; l < k; ++l)
                       temp = temp / 10;
                 temp = temp % 10;
                 insertLast(&p[temp], a[i]);     /* insertion of a[i] into the relevant list, based on the digit extracted; constant time operation due to the usage of CLL */
           }
           for(i = 0; i < 10; ++i)    /* loop runs for each of the 10 lists */
           {
                 while(p[i] != NULL)  /* if the list is not empty */
                      a[j++] = deleteFirst(&p[i]);   /* while list is not empty, move elements from list to array, in FIFO fashion ('a' is overwritten) */
           }
           /* printing the list after each pass */
           printf("\nList after %dth pass: ", k + 1);
           for(i = 0; i < n; ++i)
                 printf("%d ", a[i]);
     }
}

/* function to find the maximum key length in an array of integers */
int maxKeyLength(int *a, int n, int *flag)
{
    int max = a[0], i, len = 0;
    for(i = 1; i < n; ++i)
    {
          if(a[i] < a[i-1])  /* if input array is not sorted in non-decreasing order */
                  *flag = 1;
          if(a[i] > max)
                  max = a[i];   /* indicates maximum value in list */
    }
    while(max != 0)
    {
              max = max / 10;
              ++len;    /* counter variable indicating the number of digits in the greatest value of the list */
    }
    return len;
}

/* function to insert an element at the end of a circularly-linked list */
void insertLast(NODEPTR *p, int info)
{
     NODEPTR newNode = malloc(sizeof(struct node));     /* dynamic creation of a node */
     newNode -> val = info;    /* number is placed into the node */           
     if(*p == NULL)  /* if the list is empty */
           newNode -> next = newNode;   /* 'next' part of newNode points to itself */
     else  /* list has at least one node */
     {
           newNode -> next = (*p) -> next;     /* next' part of newNode points to first node in the list*/
           (*p) -> next = newNode;   /* last (now penultimate) node points to newNode */
     }
     *p = newNode; /* external pointer points to last node in the list, i. e., newNode */
}

/* function to delete an element from the front of a non-empty circularly-linked list */
int deleteFirst(NODEPTR *p)
{
    int info;   /* stores value present in node to be deleted */
    NODEPTR delNode; /* points to the node to be deleted */
    if((*p) -> next == *p) /* if there is only one node in the list */
    {
          info = (*p) -> val; /* copy value of node to 'info' */
          free(*p);   /* deallocate space for node */
          *p = NULL;  /* change external pointer to null */
          return info;
    }
    else /* list contains more than one node */
    {
          delNode = (*p) -> next;   /* the first node is the node to be deleted */
          info = delNode -> val;    /* copy value of delNode to 'info' */
          (*p) -> next = delNode -> next; /* 'next' part of last node points to second node */
          free(delNode); /* deallocate space for first node */
          return info;
    }
}
