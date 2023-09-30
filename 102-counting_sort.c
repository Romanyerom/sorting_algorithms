#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using counting sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array of size 'max + 1' and initialize to 0 */
	int *count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the occurrences of each element in the input array */
	for (size_t i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the input array with sorted values */
	int j = 0;
	for (int i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[j] = i;
			j++;
			count[i]--;
		}
	}

	/* Print the counting array (optional) */
	printf("%d", count[0]);
	for (int i = 1; i <= max; i++)
		printf(", %d", count[i]);
	printf("\n");

	free(count);
}
