#include <stdlib.h>
#include <stdio.h>

/**
* print_array - Prints an array of integers.
*
* @array: The array to be printed.
* @size: The number of elements in the array.
*
* Description: This function prints
*the elements of the given array,
* separated by commas, and terminates
*the output with a newline character.
*/
void print_array(const int *array, size_t size)
{
size_t i;

i = 0;
while (array && i < size)
{
if (i > 0)
printf(", ");
printf("%d", array[i]);
++i;
}
printf("\n");
}
