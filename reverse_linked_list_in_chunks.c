/*Program to perform operations on SLL*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
}*head = NULL;

void insert_sll(struct node**, int);
void display_sll(struct node*);
struct node* reverse_sll(struct node*);
struct node* reverse_list_in_chunks(struct node* head, int chunk);

int main() 
{
	int num;
        struct node* new_head = NULL;
        int chunk = 0;

	while(1) {
		printf("Enter the node to be inserted to list:");
		scanf("%d",&num);

		if(num==-1) {
			break;
		} else {
			insert_sll(&head,num);
		}
	}

	printf("Printing Single linked list\n");
	display_sll(head);

        printf("\n Reversing Linked list\n");
        new_head = reverse_sll(head);	
	
	display_sll(new_head);

        printf("\n");
    
        printf("\n Reversing Linked list in chunks\n");
        printf("Enter the chunk in which linked list nodes to be reversed:");
        scanf("%d",&chunk);

        new_head = reverse_list_in_chunks(new_head, chunk);	

        printf("Printing Linked list after chunk reversal\n");        
	display_sll(new_head);

        printf("\n");

        return 0;
}

void insert_sll(struct node** temp_head, int num)
{
	struct node* new_node = NULL;
	struct node* temp_node = *temp_head;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;

	if(*temp_head == NULL) {
		*temp_head = new_node;
	} else {
		while(temp_node->next != NULL) {
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
}

void display_sll(struct node* temp_head)
{
	while(temp_head) {
		printf("%d----", temp_head->data);
		temp_head = temp_head->next;
	}
}

struct node* reverse_sll(struct node* first)
{
    struct node* head = first;
    struct node* t_next = NULL;
    
    while(first && first->next) {
            t_next = first->next->next;
            first->next->next = head;
            head = first->next;
            first->next = t_next;
    }
    return head;
}

struct node* reverse_list_in_chunks(struct node* head, int chunk)
{
    struct node* next = NULL;
    struct node* curr_head = head;
    struct node* prev = NULL;
    int count = 0;

    while(curr_head && count < chunk) {
        next = curr_head->next;
        curr_head->next = prev;
        prev = curr_head;
        curr_head = next;
        count++;
    }

    if(next) {
        head->next = reverse_list_in_chunks(next, chunk);
    }
    return prev;
}
