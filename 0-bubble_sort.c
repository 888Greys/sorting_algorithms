#include "sort.h"

/**
* swap_ints - Swaps two integers in an array.
* @a: Pointer to the first integer to swap.
* @b: Pointer to the second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* bubble_sort - Sorts an array of integers in
*ascending order using the Bubble Sort algorithm.
* @array: Array of integers to be sorted.
* @size: Size of the array.
*
* Description: This function implements the Bubble
*Sort algorithm to arrange the elements
* of the given array in ascending order. It prints
*the array after each swap operation.
*/
void bubble_sort(int *array, size_t size)
{
size_t i, len = size;
bool bubbly = false;

if (array == NULL || size < 2)
return;

while (bubbly == false)
{
bubbly = true;
for (i = 0; i < len - 1; i++)
{
if (array[i] > array[i + 1])
{
swap_ints(array + i, array + i + 1);
print_array(array, size);
bubbly = false;
}
}
len--;
}
}
