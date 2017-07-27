#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    int weight;
    struct node *next;
};

struct pq_node
{
    int vertex;
    int weight;
};

void input_array(struct pq_node**, int);
void heapsort(struct pq_node*,int);
void display_array(struct pq_node*,int);
void swap(struct pq_node*, struct pq_node*);
void heapify(struct pq_node*,int);
int search_in_heap(struct pq_node *array, int node_to_search, int array_size);
void prim_spanning_tree(struct node**, int);
void insert_graph(struct node**, int, int);
void display_graph(struct node**, int);

int main()
{
    int num_vertices;
    int vertex;
    int i;
    int weight;

    struct node **graph = NULL;
        
    printf("Enter number of vertices in Graph:");
    scanf("%d", &num_vertices);

    graph = (struct node**)malloc(num_vertices * sizeof(struct node*));

    for(i = 0; i < num_vertices; i++) {
        while(1) {
            printf("Enter the vertex adjacent to %d vertex(To stop press -1):", i);
            scanf("%d", &vertex);
            if(vertex == -1) {
                break;
            } else {
                printf("Enter the weight from %d to %d vertex:", i, vertex);
                scanf("%d", &weight);
 
                insert_graph(&graph[i], vertex, weight);
            }
        }
    }

    printf("Displaying Graph\n");
    display_graph(graph, num_vertices);

    printf("Triggering Prim Spanning Tree\n");
    prim_spanning_tree(graph, num_vertices);

    return 0;
}

void insert_graph(struct node **head, int vertex, int weight)
{
    struct node *tmp_node = NULL;
    struct node *tmp_head = NULL;

    tmp_node = (struct node*)malloc(sizeof(struct node));
    tmp_node->vertex = vertex;
    tmp_node->weight = weight;
    tmp_node->next = NULL;

    tmp_head = *head;
    if(tmp_head == NULL) {
        *head = tmp_node;
    } else {
        while(tmp_head->next) {
            tmp_head = tmp_head->next;
        }
        tmp_head->next = tmp_node;
    }
}

void display_graph(struct node** graph, int num_vertices)
{
    int i = 0;
    struct node* temp = NULL;


    for(i = 0; i < num_vertices; i++) {
        printf("%d==>", i);
        temp = graph[i];
        while(temp) {
            printf("%d--", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void prim_spanning_tree(struct node **graph, int num_vertices)
{
    struct pq_node *array = NULL;
    int *prev = NULL;
    int i;
    struct pq_node min;
    int node_loc;
    int adj_node;

    array = (struct pq_node*)malloc(num_vertices * sizeof(struct pq_node));
    prev = (int*)malloc(num_vertices * sizeof(int));

    for(i = 0; i < num_vertices; i++) {
        array[i].vertex = i;
        array[i].weight = 9999;
        prev[i] = -99;
    }

    /*Taking 0th vertex as start vertex*/
    array[0].weight = 0;

    heapify(array, num_vertices-1);

    for(i = num_vertices-1; i >= 0; i--) {
        min = array[0];
        swap(&array[0], &array[i]);

        while(graph[min.vertex]) {
            adj_node = graph[min.vertex]->vertex;
            node_loc = search_in_heap(array, adj_node, i);
            /*Only if node is not visited*/
            if(node_loc != -1) {
                if(graph[min.vertex]->weight < array[node_loc].weight) {
                    array[node_loc].weight = graph[min.vertex]->weight;
                    prev[adj_node] = min.vertex;
                }
            }
            graph[min.vertex] = graph[min.vertex]->next;
        }
        heapify(array, i-1);
    }

    /*Printing prev array*/
    printf("\nPrinting previous node for each vertex\n");
    for(i = 0; i < num_vertices; i++) {
        printf("previous vertex of %d is %d\n", i, prev[i]);
    }
}

int search_in_heap(struct pq_node *array, int node_to_search, int array_size)
{
    int i = 0;

    for(i = 0; i < array_size; i++) {
        if(array[i].vertex == node_to_search) {
            return i;
        }
    }
    return -1;
}

void heapify(struct pq_node *array, int num)
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

void swap(struct pq_node *a, struct pq_node *b)
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

/*
void heapsort(struct pq_node *array, int num)
{
    int i;

    heapify(array, num-1);
    
    for(i=num-1; i>=0; i--) {
        swap(&array[0], &array[i]);
        heapify(array,i-1);
    }
}
*/

/*
void input_array(struct pq_node **array, int total_count)
{
    int i;
    int vertex;
    int weight;

	(*array) = (struct pq_node*)malloc((total_count)*sizeof(struct pq_node));

	for(i = 0; i < total_count; i++) {
		printf("Enter the vertex to be added:");
		scanf("%d", &vertex);
		(*array)[i].vertex = vertex;
		printf("Enter the weight to be added for %d vertex:", vertex);
                scanf("%d", &weight);
                (*array)[i].weight = weight;

	}
}

void display_array(struct pq_node *array, int total_count)
{
    int i;

   	for(i=total_count-1; i>=0; i--) {
		printf("vertex:%d--weight:%d\n", array[i].vertex,
                       array[i].weight);
	}
}
*/
