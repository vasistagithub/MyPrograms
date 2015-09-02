/*
 * Program to perform Heap sorting over 
 * given of an array of integers
 *
 * Author: Vasista Jayanth K
 * Date: 17th August 2015
 */

#include<stdio.h>
#include<stdlib.h>

void input_array(int**, int);
void heapsort(int*,int);
void display_array(int*,int);
void swap(int*, int*);
void heapify(int*,int);

int main()
{
	int *array;
	int total_count;
	
	printf("\n\n\t\t-------HEAP SORTING-------\n");
	printf("Enter the numbers of elements to be added to array:");
	scanf("%d", &total_count);

    input_array(&array, total_count);

	printf("\nElements before sorting are:\n");
    display_array(array,total_count);

    heapsort(array, total_count);

	printf("Elements after sorting are:\n");
    display_array(array,total_count);

	return 0;
}


void input_array(int **array, int total_count)
{
    int i;
    int num;

	(*array) = (int*)malloc((total_count)*sizeof(int));

	for(i = 0; i < total_count; i++) {
		printf("Enter the element to be added to array:");
		scanf("%d", &num);
		(*array)[i] = num;
	}
}

void display_array(int*array, int total_count)
{
    int i;

   	for(i=0; i<total_count; i++) {
		printf("%d---", array[i]);
	}
	printf("\n\n");
}

void heapify(int *array, int num)
{
    int i,j;
    int min, left, right;

    for(i=num/2; i>=0; i--) {
        left = 2*i;
        right = 2*i + 1;

        if(left <= num && right <= num) {
            if(array[left] < array[right]) {
                min = left;
            } else {
                min = right;
            }
            if(array[min] < array[i]) { 
                swap(&array[min], &array[i]);
            }
        } else if(left <= num && right > num) {
            if(array[left] < array[i]) {
                swap(&array[left], &array[i]);
            }
        }
    } 
}

void heapsort(int *array, int num)
{
    int i;

    heapify(array, num-1);
    
    for(i=num-1; i>0; i--) {
        swap(&array[0], &array[i]);
        heapify(array,i-1);
    }
}


void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
