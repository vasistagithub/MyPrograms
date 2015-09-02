/*
 * Program to insert graph in an Adjacency list
 * Author: Vasista Jayanth K
 * Date: 30 August 2015
 * */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
}**head = NULL;

void insert_graph(struct node**,int);
void display_graph(struct node**,int);

int main()
{
    int num_nodes;
    int i;
    int adj_node;

    printf("\n\n\t\t ADJACENCY LIST\n\n");
    printf("Enter the number of nodes::");
    scanf("%d",&num_nodes);

    head = (struct node**)malloc(num_nodes * sizeof(struct node*));

    for(i=0; i<num_nodes; i++) {
        head[i] = (struct node*)calloc(sizeof(struct node),1);
        head[i]->data = i;
        head[i]->link = NULL;
    }

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

    return 0;
}

void insert_graph(struct node** head, int graph_node)
{
    struct node *temp;
    struct node* temp_head;
    
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = graph_node;
    temp->link = NULL;

    temp_head = *head;
    
    while(temp_head->link) {
        temp_head =temp_head->link;
    }
    temp_head->link = temp;
}


void display_graph(struct node **head, int num_nodes)
{
    int i;
    struct node* temp;

    for(i=0; i<num_nodes; i++) {
        temp = head[i];
        while(temp) {
            printf("%d---",temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

