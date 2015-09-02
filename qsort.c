/*
 *  Program to perform Quick sort over array
    Author: Vasista Jayanth K
    Date: 13 August 2015
*/

#include<stdio.h>
#include<stdlib.h>

void quicksort(int*, int, int);
int partition(int*, int, int);
void swap(int*,int*);

int main()
{
    int *array;
    int total_count;
    int i;
    int num;

    printf("\t\t------- QUICK SORTING-------\n");
    printf("Enter the numbers of elements to be added to array:");
    scanf("%d", &total_count);

    array = (int*)malloc((total_count)*sizeof(int));

    for(i = 0; i < total_count; i++) {
        printf("Enter the element to be added to array:");
        scanf("%d", &num);
        array[i] = num;
    }

    printf("Elements before sorting are:\n");

    for(i=0; i<total_count; i++) {
        printf("%d---", array[i]);
    }
    printf("\n\n");

    quicksort(array, 0, total_count-1);

    printf("Elements after sorting are:\n");

    for(i=0; i<total_count; i++) {
        printf("%d---", array[i]);
    }
    printf("\n\n");

    return 0;
}

void quicksort(int *array, int lower, int upper)
{
    int pivot_loc;

    if(lower < upper) {
        pivot_loc = partition(array, lower,upper);
        quicksort(array, lower, pivot_loc-1);
        quicksort(array, pivot_loc+1, upper);
    }
}

int partition(int *array, int lower, int upper)
{
    int temp_lower;
    int temp_upper;
    int temp_var;

    temp_lower = lower;
    temp_lower++;
    temp_upper = upper;

    while(temp_lower <= temp_upper) {
        while(temp_lower <= upper && array[lower] > array[temp_lower]) {
            temp_lower++;
        }
        while(temp_upper >= lower+1 && array[lower] < array[temp_upper]) {
            temp_upper--;
        }
        swap(&array[temp_lower], &array[temp_upper]);
    }

    /*This swap is to avoid one last extra swap done at the end of while loop*/	
    swap(&array[temp_lower], &array[temp_upper]);

    /*Move pivot element to desired location*/
    swap(&array[lower],&array[temp_upper]);

    return temp_upper;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
