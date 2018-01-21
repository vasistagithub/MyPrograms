/* 
 * Program to perform Merge sort over an array
   Author: Vasista Jayanth K
   Date: 13th Aug 2015
*/

#include<stdio.h>
#include<stdlib.h>

void mergesort(int*, int, int);
void merge(int*, int, int, int);

int main()
{
	int *array;
	int total_count;
	int i;
	int num;
	
	printf("\t\t------- MERGE SORTING-------\n");
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

	mergesort(array, 0, total_count-1);

	printf("Elements after sorting are:\n");

	for(i=0; i<total_count; i++) {
		printf("%d---", array[i]);
	}
	printf("\n\n");

	return 0;
}

void mergesort(int* array, int lower, int upper)
{
	int pivot_middle;

	if(lower<upper) {
		pivot_middle = (lower + upper)/2;
		
		mergesort(array, lower, pivot_middle);
		mergesort(array, pivot_middle + 1, upper);
		
		merge(array, lower, pivot_middle, upper);
	}
}

void merge(int* array, int lower, int pivot, int upper)
{
	int list1[100], list2[100];
	int i,j,k;
	int length_list1, length_list2;

	length_list1 = pivot - lower + 1;
	length_list2 = upper -pivot;

	for(i = 0; i< length_list1; i++) {
		list1[i] = array[lower+i];
	}
	for(j = 0; j < length_list2; j++) {
		list2[j] = array[j+pivot+1];
	}
	
	i = j = 0;
	k = lower;

    /*Perform merging of two lists into one big list*/
	while(i< length_list1 && j < length_list2) {

		if(list1[i] < list2[j]) {
			array[k++] = list1[i++];
		} else {
			array[k++] = list2[j++];
		}
	}

	while(i < length_list1) {
		array[k++] = list1[i++];
	}

	while(j < length_list2) {
		array[k++] = list2[j++];
	}
}	
