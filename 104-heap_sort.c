#include "sort.h"

/**
* swap_ints - Swaps two integers in an array.
*
* This function takes two integer pointers,
*@a and @b, and swaps the values
* they point to in the given integer array.
*It prints the array after each swap.
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
print_array(a, 2);
}

/**
* max_heapify - Ensures that a subtree rooted at
*a given node follows the max heap property.
*
* This function maintains the max heap property
*for a subtree rooted at the specified node.
* It is part of the heap sort algorithm and
*prints the array after each swap.
*
* @array: Array of integers representing a binary tree.
* @size: Size of the array.
* @base: The index of the base row of the tree.
* @root: The root node of the binary tree.
*/
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;

left = 2 * root + 1;
right = 2 * root + 2;
large = root;

if (left < base && array[left] > array[large])
large = left;
if (right < base && array[right] > array[large])
large = right;

if (large != root)
{
swap_ints(array + root, array + large);
max_heapify(array, size, base, large);
}
}

/**
* heap_sort - Sorts an array of integers in
*ascending order using heap sort.
*
* This function sorts the given integer array,
*@array, in ascending order using the
* heap sort algorithm. It prints the array
*after each swap.
*
* @array: An array of integers.
* @size: The size of the array.
*/
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size <= 1)
return;

for (i = (size / 2) - 1; i >= 0; i--)
max_heapify(array, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap_ints(array, array + i);
max_heapify(array, size, i, 0);
}
}
