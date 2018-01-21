/*Program to find first continuous subarray such that given value 
 * is equal to sum of those unsigned int elements in the subarray*/
#include <stdio.h>
#include <stdlib.h>

void get_subarray_with_given_sum(int *array, int size_array, int sum_needed, int *left, int *right);
int main()
{
    int size_array;
    int *array = NULL;
    int i = 0;
    int sum_needed;
    int left = -1;
    int right = -1;

    printf("Enter size of an array:");
    scanf("%d", &size_array);

    array = (int*)malloc(size_array * sizeof(int));

    printf("Enter %d unsigned int to store in array\n", size_array);
    for(i = 0; i < size_array; i++) {
        printf("Enter %d number:", i);
        scanf("%d", &array[i]);
    }

    printf("Enter the sum_needed from elements present in array:");
    scanf("%d", &sum_needed);

    (void)get_subarray_with_given_sum(array, size_array, sum_needed, &left, &right);

    if(left != -1 && right != -1) {
        printf("%d sum is found in between %d and %d from given array\n", sum_needed,
               left, right);
    } else {
        printf("Unable to find continuous subarray of sum %d in given array\n", sum_needed);
    }

    return 0;
}

void get_subarray_with_given_sum(int *array, int size_array, int sum_needed, int *left, int *right)
{
    int i = 0;
    int j = 0;
    int while_flag = 0;
    int temp_sum = 0;

    for(i = 0; i < size_array; i++) {
        while_flag = 0;
        while(temp_sum < sum_needed && j < size_array) {
            while_flag = 1;
            temp_sum += array[j++];
        }
        if(temp_sum == sum_needed) {
            (*left) = (while_flag) ? i:i-1;
            (*right) = (while_flag) ? j-1: j;
            return;
        } else if (j < size_array) {
            temp_sum -= array[--j];
            temp_sum -= array[i];
        } else {
            return;
        }
    }
}
