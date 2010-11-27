/*
 * intsort - a trivial sorting program which sorts a randomly generated array
 *
 * TODO - read in data from data file(s)
 *
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int main(int argc, char ** argv)
{
    int * numbers;
    int   len, i;

    if(argc == 2)
        len = atoi(argv[1]);
    else
    {
        /* if unspecified, choose how long the list should be randomly.
         * cap it at 100K elements for runtime's sake */
        srand(time(NULL));
        len = rand() % 100000;
    }

    printf("Generating array of %d random int's\n", len);
    numbers = malloc(sizeof(int) * len);
    if(!numbers)
        return 1;

    for(i = 0; i < len; i++)
        numbers[i] = rand();

    printf("Sorting bubblesort, int asc\n");
    bubblesort(numbers, len, sizeof(int), int_compare_asc);

    /* verify the list is sorted ascending */
    for(i = 0; i < len-1; i++)
        if(numbers[i] > numbers[i+1])
            printf("Failure! n[%d] > n[%d] (%d, %d)\n",
                    i, i+1, numbers[i], numbers[i+1]);

    printf("Sorting bubblesort, int desc\n");
    bubblesort(numbers, len, sizeof(int), int_compare_desc);

    /* verify the list is sorted descending */
    for(i = 0; i < len-1; i++)
        if(numbers[i] < numbers[i+1])
            printf("Failure! n[%d] < n[%d] (%d, %d)\n",
                    i, i+1, numbers[i], numbers[i+1]);
    

    free(numbers);
    return 0;
}
