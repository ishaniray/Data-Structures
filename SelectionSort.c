/* Program to perform Selection Sort on an array of integers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void selectionSort(int*, int); /* function to perform Selection Sort */

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
    selectionSort(list, size);
    getch();
    return 0;
} /* end of main */

/* function definition for selectionSort */
void selectionSort(int *elems, int n)
{
     int i, j, minIndex, temp;
     for(i = 0; i < n - 1; ++i)
     {
           minIndex = i;
           for(j = i + 1; j < n; ++j)
               if(elems[j] < elems[minIndex])
                   minIndex = j;
           temp = elems[i];
           elems[i] = elems[minIndex];
           elems[minIndex] = temp;
           printf("\n\nAfter %d iteration(s), the list elements are: ", i + 1);
           for(j = 0; j < n; ++j)
               printf("%d ", elems[j]);
     }
     printf("\n\nThe array is now sorted. ");
}
