/* Program to perform Insertion Sort on an array of integers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void insertionSort(int*, int); /* function to perform Insertion Sort */

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
    insertionSort(list, size);
    getch();
    return 0;
} /* end of main */

/* function definition for Insertion Sort */
void insertionSort(int *elems, int n)
{
     int i, j, temp;
     for(i = 1; i < n; ++i)
     {
           temp = elems[i];
           for(j = i - 1; j >= 0 && temp < elems[j]; --j)
               elems[j + 1] = elems[j];
           elems[j + 1] = temp;
           printf("\n\nAfter %d iteration(s), the list elements are: ", i);
           for(j = 0; j < n; ++j)
               printf("%d ", elems[j]);
     }
     printf("\n\nThe array is now sorted. ");
}
