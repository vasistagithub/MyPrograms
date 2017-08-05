/*Program to find equilibrium point in an array 
 * such that sum of elements to left of that point is equal to
 * the sum of elements to right of the same equilibrium point*/
#include <stdio.h>
#include <stdlib.h>

int get_equilibrium_point_in_array(int array[], int size_array);

int main()
{
    int size_array;
    int *array = NULL;
    int i = 0;
    int eq_point = -1;

    printf("Enter size of an array:");
    scanf("%d", &size_array);

    array = (int*)malloc(size_array * sizeof(int));

    printf("Enter %d element to store in array\n", size_array);
    for(i = 0; i < size_array; i++) {
        printf("Enter %d number:", i);
        scanf("%d", &array[i]);
    }

    eq_point = get_equilibrium_point_in_array(array, size_array);

    if(eq_point != -1) {
        printf("Equilibrium point found at index %d in given array\n", eq_point);
    } else {
        printf("Unable to find equilibrium point in given array\n");
    }

    return 0;
}

int get_equilibrium_point_in_array(int array[], int size_array)
{
    int i = 0;
    int left_sum = 0;
    int current_sum = 0;

    for(i = 0; i < size_array; i++) {
        current_sum += array[i];
    }

    for(i = 0; i < size_array; i++) {
        current_sum -= array[i];

        if(left_sum == current_sum) {
            return i;
        } else {
            left_sum += array[i];
        }
    }
    return -1;
}


