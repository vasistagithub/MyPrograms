/*
 * Program to insert graph in an Adjacency list
 * Author: Vasista Jayanth K
 * Date: 30 August 2015
 * */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    struct node* next;
}**head = NULL;

struct node* front = NULL;
struct node* rear = NULL;
struct node* top = NULL;

int *parent = NULL;
int *color = NULL;
 
void insert_graph(struct node**,int);
void display_graph(struct node**,int);
void BFS(struct node**, int);
void DFS(struct node**, int);

int main()
{
    int num_nodes;
    int i;
    int adj_node;

    printf("\n\n\t\t GRAPH OPERATIONS\n\n");
    printf("Represent Graph in Adjacency list\n");
    printf("Enter the number of nodes::");
    scanf("%d",&num_nodes);

    head = (struct node**)malloc(num_nodes * sizeof(struct node*));

    for(i=0; i<num_nodes; i++) {
        while(1) {
            printf("Enter the nodes adjacent to node %d(To stop press -1):",i);
            scanf("%d",&adj_node);
            if(adj_node == -1) {
                break;
            } else {
                insert_graph(&head[i],adj_node);
            }
        }
    }
 
    printf("\nDisplaying graph in adjacency list format\n\n");
    display_graph(head, num_nodes);

    printf("\n Performing BFS on Graph\n");
    BFS(head, num_nodes);
    
    printf("\n Performing DFS on Graph\n");
    DFS(head, num_nodes);

    return 0;
}

void insert_graph(struct node** head, int graph_node)
{
    struct node *temp;
    struct node* temp_head;
    
    temp = (struct node*)malloc(sizeof(struct node));
    temp->vertex = graph_node;
    temp->next = NULL;

    temp_head = *head;

    if(temp_head == NULL) {
        *head = temp;
    } else {    
       while(temp_head->next) {
           temp_head = temp_head->next;
       }
        temp_head->next = temp;
    }
}


void display_graph(struct node **head, int num_nodes)
{
    int i;
    struct node* temp;

    for(i=0; i<num_nodes; i++) {
        temp = head[i];
        while(temp) {
            printf("%d---",temp->vertex);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

void enqueue(int vertex)
{
    struct node* tmp = NULL;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->vertex = vertex;
    tmp->next = NULL;

    if(front == NULL) {
        front =rear = tmp;
    } else {
        rear->next = tmp;
        rear = tmp;
    }
}

int queue_empty()
{
    if(front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int dequeue()
{
    int vertex = front->vertex;
 
    front = front->next;
    return vertex;
}
void BFS(struct node **head, int num_vertices)
{
    int flag = 0;
    int tmp_vertex = 0;
    int i = 0;
    struct node* tmp_node = NULL;

    parent = (int*)malloc(num_vertices*sizeof(int));
    color  = (int*)malloc(num_vertices*sizeof(int));


    for(i = 0; i < num_vertices ; i++) {
        color[i] = 0;
        parent[i] = -9999;
    }

    parent[0] = -9999;
    color[0] = 1;
    enqueue(0);
    while(!queue_empty()) {
        tmp_vertex = dequeue();
        printf("%d--", tmp_vertex);
        tmp_node = head[tmp_vertex];

        while(tmp_node) {
            if(color[tmp_node->vertex] == 0) {
                parent[tmp_node->vertex] = tmp_vertex;
                color[tmp_node->vertex] = 1;
                enqueue(tmp_node->vertex);
            }
            tmp_node = tmp_node->next;
        }
        color[head[tmp_vertex]->vertex] = 2;
   
    }
}


void push(int vertex)
{
    struct node* tmp = NULL;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->vertex = vertex;
    tmp->next = NULL;

    if(top == NULL) {
        top = tmp;
    } else {
        tmp->next = top;
        top = tmp;
    }
}

int pop()
{
    int vertex = top->vertex;
    top = top->next;

    return vertex;
}

int stack_empty()
{
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void DFS(struct node **head, int num_vertices)
{
    int tmp_vertex = 0;
    int i = 0;
    struct node* tmp_node = NULL;

    parent = (int*)malloc(num_vertices*sizeof(int));
    color  = (int*)malloc(num_vertices*sizeof(int));


    for(i = 0; i < num_vertices ; i++) {
        color[i] = 0;
        parent[i] = -9999;
    }

    parent[0] = -9999;
    color[0] = 1;
    push(0);
    while(!stack_empty()) {
        tmp_vertex = pop();
        printf("%d--", tmp_vertex);
        tmp_node = head[tmp_vertex];

        while(tmp_node) {
            if(color[tmp_node->vertex] == 0) {
                parent[tmp_node->vertex] = tmp_vertex;
                color[tmp_node->vertex] = 1;
                push(tmp_node->vertex);
            }
            tmp_node = tmp_node->next;
        }
        color[head[tmp_vertex]->vertex] = 2;
   
    }
}
