#include "sort.h"

/**
* swap_ints - Swaps two integer values.
*
* This function takes two integer pointers,
*@a and @b, and swaps the values they point to.
*
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
* Return: void
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *b;
*b = *a;
*a = tmp;
}

/**
* selection_sort - Sorts an array of integers
*in ascending order
*using the selection sort algorithm.
*
* This function implements the selection sort
*algorithm to arrange the elements
* of the given integer array, @array, in ascending
*order. The sorting process is
* performed in-place, and the array is printed
*after each swap operation.
*
* @array: The array of integers to be sorted.
* @size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
size_t i, j, min_index;

if (array == NULL || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
min_index = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_index])
{
min_index = j;
}
}

if (min_index != i)
{
swap_ints(&array[min_index], &array[i]);
print_array(array, size);
}
}
}
