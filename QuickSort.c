/* This program performs Quick Sort on an array of integers, taking the mid element of each subarray as the pivot */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int* quickSort(int*, int, int); /* function to perform QuickSort */
int partition(int*, int, int); /* function to partition the array and subsequent subarrays */
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
	a = quickSort(a, 0, n - 1);
	display(a, n);
	getch();
	return 0;
} /* end of main */

/* function definition for quickSort */
int* quickSort(int *a, int low, int high)
{
	int pivotPos, i;
	if(low < high)
	{
		pivotPos = partition(a, low, high);
		quickSort(a, low, pivotPos - 1);
		quickSort(a, pivotPos + 1, high);
	}
    return a;
}

/* function definition for partition */
int partition(int *a, int low, int high)
{
	int pivot, mid, lastSmall, temp, i;
	mid = low + (high - low / 2);
	temp = a[low];
	a[low] = a[mid];
	a[mid] = temp;
	pivot = a[low];
	lastSmall = low;
	for(i = low + 1; i <= high; ++i)
	{
		if(a[i] < pivot)
		{
			++lastSmall;
			temp = a[i];
			a[i] = a[lastSmall];
			a[lastSmall] = temp;
		}
	}
	a[low] = a[lastSmall];
	a[lastSmall] = pivot;
	return lastSmall;
}

/* function definition for display */
void display(int *a, int n)
{
	int i;
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
}
