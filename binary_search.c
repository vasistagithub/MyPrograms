/*
 * Program to perform Binary search
 * Author: Vasista Jayanth K
 * Date: 17th August 2015
 * */

#include<stdio.h>
#include<stdlib.h>

int binary_search(int*, int, int, int);

int main()
{
    int *array;
    int total_count;
    int num_to_search;
    int return_loc;
    int i;

    printf("Enter no of  elements to be added to array:");
    scanf("%d",&total_count);

    array = (int*)malloc(sizeof(int)*total_count);

    i=0;
    while(i < total_count) {
        printf("Enter the number to be added to array:");
        scanf("%d",&num_to_search);

        if(num_to_search == -1) {
            break;
        } else {
            array[i++] = num_to_search;
        }
    }   

    printf("Enter the number to be searched:");
    scanf("%d",&num_to_search);

    return_loc = binary_search(array, 0, total_count, num_to_search);    

    if(return_loc == -1) {
        printf("%d not found in the array\n\n", num_to_search);
    } else {
        printf("%d is found at location %d\n\n", num_to_search, return_loc);
    }

    return 0;

}

int binary_search(int *array, int lower, int upper, int num)
{
    int mid;

    while(lower <= upper) {
        mid = (upper + lower)/2; 

        if(array[mid] == num) {
            return mid;
        } else if (array[mid] < num) {
            lower = mid + 1;
        } else {
            upper = mid - 1 ;
        }
    }
    return -1;
}
