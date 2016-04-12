/*Program to print a matrix in spiral format
  Author: Vasista Jayanth K
  Date: 25Sept 2015
*/


#include<stdlib.h>
#include<stdio.h>

int* spiralOrder(const int** A, int n11, int n12, int *length_of_array); 

int main() 
{
	int **A;
	int len_new_array;
	int i,j;
	int rows,col;
	int *new_array;
	
	printf("Enter the matrix number of rows:");
	scanf("%d",&rows);
	
	printf("Enter the number of columns:");
	scanf("%d",&col);
	
	A = (int**)malloc(sizeof(int*)*rows);
	
	for(i=0;i<rows; i++) {
	 	A[i] = (int*)malloc(sizeof(int)*col);
	 }
	 
	for(i=0; i<rows; i++) {
		printf("Enter %d elements for %d row\n",col, i+1);
		for(j=0; j<col; j++) {
			scanf("%d",&A[i][j]);
		}
	}
	
	new_array = spiralOrder((const int**)A, rows, col, &len_new_array);
	
	for(i=0; i<len_new_array; i++) {
		printf("%d",new_array[i]);
	}
	
	return 0;
	
}

int *spiralOrder(const int** A, int n11, int n12, int* length_of_array)
{
	int dir = 0;
	int T = 0;
	int B = n11-1;
	int L = 0;
	int R = n12-1;
	int i;
	int cur_loc = 0;
	int *ret_array;
	
	*length_of_array = n11*n12;
	ret_array = (int*)malloc((*length_of_array)*sizeof(int));
	
	while((T <= B) && (L <= R)) {
		if(dir == 0) {
			for(i=L; i<=R; i++) {
				ret_array[cur_loc++] = A[T][i];
			}
			T++;
		} else if(dir == 1) {
			for(i=T; i<=B; i++) {
				ret_array[cur_loc++] = A[i][R];	
			}
			R--;
		} else if(dir == 2) {
			for(i=R; i>=L; i--) {
				ret_array[cur_loc++] = A[B][i]; 
			}
			B--;
		} else {
			for(i=B; i>=T; i--) {
				ret_array[cur_loc++] = A[i][L];	
			}
			L++;
		}
		dir = (dir+1)%4;
	}
	
	return ret_array;
}
					
	


