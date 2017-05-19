/* This program implements a priority queue via a maxheap. */
/* Priority of each number is indicated by its value */
/* The queue is in the form of an array */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSIZE 10

/* function prototypes */
void heapify(int*, int);
void insertHeap(int, int, int, int*);

int main(void)
{
    int *a;
    a = malloc(MAXSIZE * sizeof(int));
    int choice, item, n = 0;
    do
    {
                printf("\n\n------------------- MENU ---------------------");
                printf("\n1. APPEND           2. SERVE           3. EXIT");
                printf("\n----------------------------------------------");
                printf("\n\nEnter your choice: ");
                scanf("%d", &choice);
                switch(choice)
                {
                              case 1:     if(n == MAXSIZE)
                                          {
                                               printf("\n\nOverflow!");
                                               break;
                                          }
                                          else
                                          {
                                               printf("\n\nEnter number: ");
                                               scanf("%d", &item);
                                               a[n++] = item;
                                               printf("\n\n%d was successfully appended to queue.", item);
                                               break;
                                          }
                                          
                              case 2:     if(n == 0)
                                          {
                                               printf("\n\nUnderflow!");
                                               break;
                                          }
                                          else
                                          {
                                               heapify(a, n);           /* heapify array */
                                               item = a[0];             /* element with greatest priority, i.e., a[0] of the heapified array, is the item to be served */
                                               printf("\n\nServed item is: %d", item);
                                               a[0] = a[n - 1];        /* bring last element to the front */
                                               --n;                    /* decrement number of elements in the array (queue) by one */
                                               break;
                                          }
                                          
                              case 3:     exit(0);
                                          
                              default:    printf("\nInvalid choice! Try again.");
                }
    } while(choice != 3);                    
    getch();
    return 0;
}

/* function to heapify an array */
void heapify(int *a, int n)
{
     int low;
     for(low = n / 2 - 1; low >= 0; --low)
           insertHeap(a[low], low, n - 1, a);
}

/* function to insert an element into a heap */
void insertHeap(int current, int low, int high, int *a)
{
     int large;
     large = 2 * low + 1;
     while(large <= high)
     {
                 if(large < high && a[large] < a[large + 1])
                          ++large;
                 if(current > a[large])
                            break;
                 else
                 {
                     a[low] = a[large];
                     low = large;
                     large = 2 * low + 1;
                 }
     }
     a[low] = current;
}
