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
 * element
 * @arr: array or subarray, as the case may be, to be partitioned
 * @lb: index of lower bound of array or subarray
 * @ub: index of upper bound of array or subarray
 * Return: location / index of the pivot element
 */
int partition_array(int *arr, int lb, int ub)
{
	int start, end, pivot;

	start = lb;
	end = ub;
	pivot = arr[lb];

	if (arr == NULL)
		return (1);

	while (start < end)
	{
		/* stops if element is > pivot; element is arr[start] */
		while (arr[start] <= pivot)
			start++;

		/* stops if element is < pivot; element is arr[end] */
		while (arr[end] > pivot)
			end--;

		/**
		 * move element > pivot to the R.H.S,
		 * and the element < pivot to the L.H.S
		 */
		if (start < end)
			swap_elements(&arr[start], &arr[end]);
	}

	/**
	 * arr[end] is < arr[lb], since arr[lb] is the pivot element;
	 * end stops when a certain point is reached
	 * in the loop when an element lower than pivot is reached
	 * hence, moves the pivot element to the 'center' of the partitioned
	 * array [ elements < pivot | pivot | elements > pivot ]
	 */
	swap_elements(&arr[lb], &arr[end]);

	return (end);
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
	int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
	int arr2[] = {0};

	size = sizeof(arr) / sizeof(int);

	printf("===== Before sorting ======\n");

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
