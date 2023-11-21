#include "sort.h"

/**
* swap_ints - Swaps two integers in an array.
*
* This function takes two integer pointers,
*@a and @b, and swaps the values
* they point to in the given integer array.
*
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* lomuto_partition - Orders a subset of an
*array using the Lomuto partition scheme.
*
* This function rearranges a portion of
*the given integer array, @array, in the
* range [@left, @right], based on the
*Lomuto partition scheme with the last
* element as the pivot. It returns the
*final partition index.
*
* @array: The array of integers.
* @size: The size of the array.
* @left: The starting index of the subset to order.
* @right: The ending index of the subset to order.
*
* Return: The final partition index.
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *pivot, above, below;

pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
swap_ints(array + below, array + above);
print_array(array, size);
}
above++;
}
}

if (array[above] > *pivot)
{
swap_ints(array + above, pivot);
print_array(array, size);
}

return (above);
}

/**
* lomuto_sort - Implements the quicksort
*algorithm through recursion.
*
* This function recursively applies the Lomuto
*partition scheme to sort the
* given integer array, @array, in the range [@left, @right].
*
* @array: An array of integers to sort.
* @size: The size of the array.
* @left: The starting index of the array partition to order.
* @right: The ending index of the array partition to order.
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
int part;

if (right - left > 0)
{
part = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, part - 1);
lomuto_sort(array, size, part + 1, right);
}
}

/**
* quick_sort - Sorts an array of integers in
*ascending order using quicksort.
*
* This function sorts the given integer array,
*@array, in ascending order
* using the quicksort algorithm with the Lomuto
*partition scheme. It prints
* the array after each swap of two elements.
*
* @array: An array of integers.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
