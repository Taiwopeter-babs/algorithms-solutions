#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * swap_elements - swaps positions of elements in an array
 * @a: first element to be swapped
 * @b: second element to swap with first element
 * Return: nothing
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;

	*a = *b;

	*b = temp;
}

/**
 * partition_array - separats the array elements, based on the pivot
 * element. It uses the Lomuto partition - last element in the array
 * is picked as pivot.
 * @arr: array or subarray, as the case may be, to be partitioned
 * @lb: index of lower bound of array or subarray
 * @ub: index of upper bound of array or subarray
 * Return: location / index of the pivot element
 */
int partition_array(int *arr, int lb, int ub)
{
	int start, end, pivot;

	start = lb;
	end = lb;
	pivot = arr[ub];

	if (arr == NULL)
		return (1);

	while (end < ub)
	{
		/* if element is <= pivot; swap occurs */
		if (arr[end] <= pivot)
		{
			swap_elements(&arr[start], &arr[end]);
			/* increment the pointer on the element > pivot */
			start++;
		}
		/* increment the pointer on the element <= pivot */
		end++;
	}

	/**
	 * arr[start] is > arr[ub], since start is on the element > pivot
	 * hence, moves the pivot element to the 'center' of the partitioned
	 * array [ elements < pivot | pivot | elements > pivot ]
	 */
	swap_elements(&arr[start], &arr[ub]);

	return (start);
}
/**
 * quick_sort - recursive function repeating partitioning and sorting
 * @arr: parameter array
 * @lb: lower bound of array. This changes as function is called
 * @ub: upper bound of array. Also changes as function is recursively called
 * Return: nothing
 */
void quick_sort(int *arr, int lb, int ub)
{
	int loc;

	if (arr == NULL)
		exit(1);

	if (lb < ub)
	{
		loc = partition_array(arr, lb, ub);
		quick_sort(arr, lb, loc - 1);
		quick_sort(arr, loc + 1, ub);
	}

	return;

}
/**
 * main - Entry point
 *
 * Return: always 0
 */
int main(void)
{
	int i, size;
	int arr[] = {1, 3, 6, 8, 9, 12, 4};
	int arr2[] = {0};

	size = sizeof(arr) / sizeof(int);

	printf("===== Before sorting ======\n");
	
	printf("size => %d\n", size); 
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	quick_sort(arr, 0, size);

	printf("===== After Sorting =====\n");

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return (0);
}
