/*Program to fetch max sum from an array of 
 * both positive and negative numbers using
 * Kadane Algorithm[Dynamic Programming]
 * */
#include <stdio.h>
#include <stdlib.h>

int kadane_algorithm (int *array, int size);

int main()
{
    int *array = NULL;
    int size_array = 0;
    int max_sum = -9999;
    int i = 0;

    printf("Enter size of an array:");
    scanf("%d", &size_array);

    if(size_array < 0) {
        printf("array size cannot be less than 0\n");
        return -1;
    }
    array = (int*)malloc(size_array * sizeof(int));

    printf("Enter %d elements into array\n", size_array);

    for(i = 0; i < size_array; i++) {
        printf("Enter %d element:", i);
        scanf("%d", &array[i]);
    }

    max_sum = kadane_algorithm(array, size_array);

    printf("max sum is %d\n", max_sum);

    return 0;

}

int kadane_algorithm (int *array, int size)
{
    int i = 0;
    int current_sum = 0;
    int max_so_far = 0;
    int first = 0;
    int last = 0;
    int tmp_first = 0;

    current_sum = array[0];
    max_so_far = array[0];

    for(i = 1; i < size; i++) {
        /*Comparing current number and 
         * previous sum + current number*/
        if(array[i] > current_sum + array[i]) {
            current_sum = array[i];
            tmp_first = i;
        } else {
            current_sum = current_sum + array[i];
        }

        if(max_so_far < current_sum) {
            last = i;
            max_so_far = current_sum;

            if(tmp_first != first) {
                first = tmp_first;
            }
        }
    }
    printf("first index:%d and last index:%d\n", first, last);

    return max_so_far;
}
