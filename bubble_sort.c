/*
 * Program to perform Bubble sorting over 
 * given of an array of integers
 *
 * Author: Vasista Jayanth K
 * Date: 17th August 2015
 */

#include<stdio.h>
#include<stdlib.h>

void input_array(int**, int);
void bubblesort(int*,int);
void display_array(int*,int);
void swap(int*, int*);

int main()
{
	int *array;
	int total_count;
	
	printf("\t\t-------BUBBLE SORTING-------\n");
	printf("Enter the numbers of elements to be added to array:");
	scanf("%d", &total_count);

    input_array(&array, total_count);

	printf("\nElements before sorting are:\n");
    display_array(array,total_count);

    bubblesort(array, total_count);

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

void bubblesort(int *array, int num)
{
    int i,j;

    for(i = 0; i < num; i++) {
        for(j = 0; j< num-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j+1], &array[j]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
