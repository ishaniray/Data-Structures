/* This program performs Merge Sort on an array of integers */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int* mergeSort(int*, int, int); /* function to perform Merge Sort */
void merge(int*, int, int, int); /* function to merge subarrays into sorted arrays */
void display(int*, int); /* function to display the sorted array */

/* main */
int main(void)
{
	int *a, n, i;
	printf("How many elements?\n");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	printf("\n\nEnter elements one by one:\n");
	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printf("\n\nThe list you entered is: ");
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\nThe list, sorted in ascending order: ");
	a = mergeSort(a, 0, n - 1);
	display(a, n);
	getch();
	return 0;
} /* end of main */

/* function definition for quickSort */
int* mergeSort(int *a, int low, int high)
{
     int mid;
     if(low < high)
     {
            mid = low + (high - low) / 2;
            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);
            merge(a, low, mid, high);
     }
     return a;
}

/* function definition for merge */
void merge(int *a, int low, int mid, int high)
{
     int i, j, k, *b;
     b = (int*)malloc((high + 1) * sizeof(int));
     for(i = low; i <= high; ++i)
           b[i] = a[i];
     i = low;
     j = mid + 1;
     k = low;
     while(i <= mid && j <= high)
     {
             if(b[i] <= b[j])
                     a[k++] = b[i++];
             else
                 a[k++] = b[j++];
     }
     while(i <= mid)
             a[k++] = b[i++];
}

/* function definition for display */
void display(int *a, int n)
{
	int i;
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
}
