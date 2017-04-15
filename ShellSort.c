/* Program to perform Shell Sort on an array of integers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void shellSort(int*, int); /* function to perform Shell Sort */
void sortInterval(int*, int, int, int); /* function to sort numbers in a group (modified Insertion Sort) */

/* main */
int main(void)
{
    int *list, size, index;
    printf("How many elements?\n");
    scanf("%d", &size);
    list = (int*)malloc(size * sizeof(int));
    printf("\n\nEnter elements one by one:\n");
    for(index = 0; index < size; ++index)
        scanf("%d", &list[index]);
    printf("\n\nBefore sorting, the list elements are - ");
    for(index = 0; index < size; ++index)
        printf("%d ", list[index]);
    shellSort(list, size);
    getch();
    return 0;
} /* end of main */

/* function definition for shellSort */
void shellSort(int *elems, int n)
{
     int increment, start, index;
     increment = n;
     do
     {
               increment = increment / 3 + 1;
               for(start = 0; start < increment; ++start)
                   sortInterval(elems, n, start, increment);
               printf("\n\n%d-sort: The list elements are - ", increment);
               for(index = 0; index < n; ++index)
                   printf("%d ", elems[index]);
     } while(increment > 1);
}

/* function definition for sortInterval */
void sortInterval(int *elems, int n, int start, int increment)
{
     int i, j, temp;
     for(i = start + increment; i < n; i = i + increment)
     {
           temp = elems[i];
           for(j = i - increment; j >= start && elems[j] > temp; j = j - increment)
               elems[j + increment] = elems[j];
           elems[j + increment] = temp;
     }
}
    
