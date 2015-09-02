/*Program to perform insertion sorting
 * Author: Vasista Jaynth K
 * Date: 13th August 2015
 * */

#include<stdio.h>
#include<stdlib.h>

void input_array(int**, int);
void insertionsort(int*,int);
void display_array(int*,int);

int main()
{
	int *array;
	int total_count;
	
	printf("\n\n\t\t-------INSERTION SORTING-------\n");
	printf("Enter the numbers of elements to be added to array:");
	scanf("%d", &total_count);

    input_array(&array, total_count);

	printf("\nElements before sorting are:\n");
    display_array(array,total_count);

    insertionsort(array, total_count);

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

void insertionsort(int *array, int total_count)
{
        int i,j;
        int temp_i;
        int temp;

        for(i = 0;i < total_count; i++) {
               temp = array[i];
               j = 0;
               temp_i = i;
               while(j<i && array[i] > array[j]) {    
                    j++;
               }
               while(j!=i && j+1 <= temp_i) {
                        array[temp_i] = array[temp_i-1];
                        temp_i--;
                   }
               array[j] = temp;
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
