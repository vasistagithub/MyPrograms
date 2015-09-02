/*Program to perform operations on SLL*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
}*head = NULL;

void insert_sll(struct node**, int);
void display_sll(struct node*);
void delete_sll(struct node*, int);

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

	printf("Enter the number to be deleted from SLL:");
	scanf("%d",&num);

	delete_sll(head,num);

	printf("SLL after deleting %d\n", num);

	display_sll(head);
	
	return 0;
}

void insert_sll(struct node** temp_head, int num)
{
	struct node* new_node = NULL;
	struct node* temp_node = *temp_head;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->link = NULL;

	if(*temp_head == NULL) {
		*temp_head = new_node;
	} else {
		while(temp_node->link != NULL) {
			temp_node = temp_node->link;
		}
		temp_node->link = new_node;
	}
}

void display_sll(struct node* temp_head)
{
	while(temp_head) {
		printf("%d----", temp_head->data);
		temp_head = temp_head->link;
	}
}

void delete_sll(struct node* temp_head, int num)
{
	struct node* parent;

	if(temp_head) {
		if(temp_head->data == num) {
			head = temp_head->link;
		} else {
			parent = temp_head;
			temp_head = temp_head->link;

			while(temp_head != NULL && temp_head->data != num) {
				parent = temp_head;
				temp_head = temp_head->link;
			}

			if(temp_head == NULL) {
				printf("Unable to find the %d in SLL\n", num);
			} else {
				parent->link = temp_head->link;
			}
		}
	}
}
