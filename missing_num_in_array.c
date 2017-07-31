/*To find missing num in an array of given n-1 elements out of n elements*/
#include <stdio.h>
#include <stdlib.h>

int find_missing_num (int array[], int size_array);

int main()
{
    int size_array;
    int *array = NULL;
    int i = 0;
    int missing_num;

    printf("Enter the size of array:");
    scanf("%d", &size_array);

    array = (int*)malloc(size_array * sizeof(int));

    for(i = 0; i <size_array; i++) {
        scanf("%d", &array[i]);
    }

    missing_num = find_missing_num(array, size_array);

    printf("Missing number in given array is %d\n", missing_num);

    return 0;
}

int find_missing_num (int array[], int size_array)
{
    int sum_needed = 0;
    int current_sum = 0;
    int i = 0;

    sum_needed = ((size_array+1)*(size_array+2))/2;

    for(i = 0; i < size_array; i++) {
        current_sum += array[i];
    }

    return (sum_needed -current_sum);
}
