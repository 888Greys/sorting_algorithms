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
* shell_sort - Sorts an array of integers in
*ascending order using shell sort.
*
* This function sorts the given integer array,
*@array, in ascending order
* using the shell sort algorithm with the Knuth
*sequence. It prints the array
* after each swap of two elements.
*
* @array: The array to sort.
* @size: The size of the array.
*/
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;

if (array == NULL || size < 2)
return;

for (gap = 1; gap < (size / 3);)
gap = gap * 3 + 1;

for (; gap >= 1; gap /= 3)
{
for (i = gap; i < size; i++)
{
j = i;
while (j >= gap && array[j - gap] > array[j])
{
swap_ints(array + j, array + (j - gap));
j -= gap;
}
}
print_array(array, size);
}
}
