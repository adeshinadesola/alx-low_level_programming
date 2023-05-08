#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;
    size_t curr = 0;

    if (array == NULL)
        return (-1);

    while (array[curr] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
        prev = curr;
        curr += step;
        if (curr >= size)
            break;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

    curr = (curr >= size) ? size - 1 : curr;

    while (array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        prev++;
        if (prev == (curr + 1) || prev == size)
            return (-1);
    }

    if (array[prev] == value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
return (prev);
    }
    return (-1);
}

