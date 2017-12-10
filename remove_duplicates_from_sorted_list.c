#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
}*head = NULL;

void insert_sll(struct node**, int);
void display_sll(struct node*);
struct node* remove_duplicates_from_sorted_list(struct node* head);

struct node* remove_duplicates_from_sorted_list(struct node* head)
{
    struct node* tmp_head = head;
    struct node* curr_ptr = head;

    if(head) {
        curr_ptr = head;
        head = head->next;
        
        while(head){
            if(head->data != curr_ptr->data) {
                curr_ptr->next = head;
                curr_ptr = head;
            }
            head = head->next;
        }
        curr_ptr->next = head;
    }

    return tmp_head;
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

int main() 
{
	int num;

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

        printf("\n");
        
        printf("Removing duplicates from sorted linked list\n");
        head = remove_duplicates_from_sorted_list(head);
        
        printf("Printing Single linked list after removing duplicates\n");
	display_sll(head);

        printf("\n");

        return 0;
}


