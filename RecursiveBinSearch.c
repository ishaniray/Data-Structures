/* Program to perform Binary Search on a list of integers using recursion */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int recBinSearch(int*, int, int, int); /* function to perform recursive binary search */

/* main */
int main(void)
{
    int *list, size, index, key, pos;
    printf("How many elements are there in the list?\n");
    scanf("%d", &size);
    list = (int*)malloc(size * sizeof(int));
    printf("\n\nEnter elements in ascending order:\n");
    for(index = 0; index < size; ++index)
        scanf("%d", &list[index]);
    printf("\n\nEnter the item to search for:\n");
    scanf("%d", &key);
    pos = recBinSearch(list, 0, size - 1, key);
    if(pos == -1)
        printf("\n%d was not found on the list.\n", key);
    else
        printf("\n%d was found at Position %d.\n", key, pos + 1);
    getch();
    return 0;
} /* end of main */

/* function definition for recBinSearch */
int recBinSearch(int *elems, int low, int high, int item)
{
    int mid;
    if(low > high)
       return -1;    /* base case 1 */
    mid = low + (high - low) / 2;
    if(item == elems[mid])
        return mid;    /* base case 2 */
    if(item > elems[mid])
        return recBinSearch(elems, mid + 1, high, item);
    else
        return recBinSearch(elems, low, mid - 1, item);
}
