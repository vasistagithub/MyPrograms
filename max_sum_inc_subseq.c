/*Program to find maximum sum increasing in a subsequence of a
 * complete array */ 
#include <stdio.h>
#include <stdlib.h>

int get_max_sum_inc_subseq(int array[], int size_array, int *first, int *last);

int main()
{
    int size_array;
    int *array = NULL;
    int i = 0;
    int max_sum = -9999;
    int first = -1;
    int last = -1;

    printf("Enter size of an array:");
    scanf("%d", &size_array);

    array = (int*)malloc(size_array * sizeof(int));

    printf("Enter %d element to store in array\n", size_array);
    for(i = 0; i < size_array; i++) {
        printf("Enter %d number:", i);
        scanf("%d", &array[i]);
    }

    max_sum = get_max_sum_inc_subseq(array, size_array, &first, &last);

    if(max_sum != -9999) {
        printf("Max sum %d  is present between %d and %d indices in given array\n", max_sum, first, last);
    } else {
        printf("Unable to find max sum in given array\n");
    }

    return 0;
}

int get_max_sum_inc_subseq(int array[], int size_array, int *first, int *last)
{
    int i = 0;
    int max_sum = -9999;
    int curr_sum = 0;
    int j = 0;

    for(i = 0; i < size_array; i++) {
        j = i;
        curr_sum = array[j];
        while(j < size_array && array[j] < array[j+1]) {
            curr_sum += array[++j];
        }
        printf("curr_sum is %d\n", curr_sum);
        printf("value of j is %d\n", j);

        if(curr_sum > max_sum) {
            max_sum = curr_sum;
            (*first) = i;
            (*last) = j;
        }
        i = j;
    }
    return max_sum;
}


