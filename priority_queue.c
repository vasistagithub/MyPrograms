/*Priority queue*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    int weight;
};

void input_array(struct node**, int);
void heapsort(struct node*,int);
void display_array(struct node*,int);
void swap(struct node*, struct node*);
void heapify(struct node*,int);

int main()
{
    struct node *array;
    int total_count;

    printf("\n\n\t\t-------MIN PRIORITY QUEUE-------\n");
    printf("Enter the numbers of elements to be added to priority queue:");
    scanf("%d", &total_count);

    input_array(&array, total_count);

    printf("\nElements before sorting are:\n");
    display_array(array,total_count);

    heapsort(array, total_count);

    printf("Elements after sorting are:\n");
    display_array(array,total_count);

    return 0;
}


void input_array(struct node **array, int total_count)
{
    int i;
    int vertex;
    int weight;

	(*array) = (struct node*)malloc((total_count)*sizeof(struct node));

	for(i = 0; i < total_count; i++) {
		printf("Enter the vertex to be added:");
		scanf("%d", &vertex);
		(*array)[i].vertex = vertex;
		printf("Enter the weight to be added for %d vertex:", vertex);
                scanf("%d", &weight);
                (*array)[i].weight = weight;

	}
}

void display_array(struct node *array, int total_count)
{
    int i;

   	for(i=total_count-1; i>=0; i--) {
		printf("vertex:%d--weight:%d\n", array[i].vertex,
                       array[i].weight);
	}
}

void heapify(struct node *array, int num)
{
    int i,j;
    int min, left, right;

    for(i=num/2; i>=0; i--) {
        left = 2*i;
        right = 2*i + 1;

        if(left <= num && right <= num) {
            if(array[left].weight < array[right].weight) {
                min = left;
            } else {
                min = right;
            }
            if(array[min].weight < array[i].weight) { 
                swap(&array[min], &array[i]);
            }
        } else if(left <= num && right > num) {
            if(array[left].weight < array[i].weight) {
                swap(&array[left], &array[i]);
            }
        }
    } 
}

void heapsort(struct node *array, int num)
{
    int i;

    heapify(array, num-1);
    
    for(i=num-1; i>=0; i--) {
        swap(&array[0], &array[i]);
        heapify(array,i-1);
    }
}


void swap(struct node *a, struct node *b)
{
    int tmp_weight;
    int tmp_vertex;

    tmp_weight = a->weight;
    tmp_vertex = a->vertex;

    (*a).vertex = (*b).vertex;
    (*a).weight = (*b).weight;

    (*b).weight = tmp_weight;
    (*b).vertex = tmp_vertex;
}
