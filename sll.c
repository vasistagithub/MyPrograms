/*Program to perform operations on SLL*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
}*head = NULL;

void insert_sll(struct node**, int);
void display_sll(struct node*);
struct node* delete_sll(struct node*, int);
struct node* delete_node_recur(struct node* ,int);
void reverse_linked_list(struct node*, struct node**);

int main() 
{
	int num;
        struct node* new_head = NULL;

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

        printf("\nReversing linked list\n");
        reverse_linked_list(head, &new_head);
	
        printf("Printing the Reversed Single Linked List\n");
	display_sll(new_head);

        printf("\nEnter the number to be deleted from updated SLL:");
	scanf("%d",&num);

	new_head = delete_sll(new_head,num);
	
        printf("\nSLL after deleting %d\n", num);
	display_sll(new_head);
	
        printf("\nEnter the number to be deleted from SLL:");
	scanf("%d",&num);
        
        new_head = delete_node_recur(new_head, num);	
	
        printf("\nSLL after deleting %d\n", num);
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

struct node* delete_sll(struct node* head, int num)
{
	struct node* parent;
        struct node* tmp_head = head;

	if(head) {
		if(head->data == num) {
			return head->link;
		} else {
			parent = head;
			head = head->link;

			while(head != NULL && head->data != num) {
				parent = head;
				head = head->link;
			}

			if(head == NULL) {
				printf("Unable to find the %d in SLL\n", num);
			} else {
				parent->link = head->link;
			}
		}
	}
        return tmp_head;
}

struct node* delete_node_recur(struct node* head, int num)
{
    if(head) {
        if(head->data == num) {
            return head->link;
        } else {
            head->link = delete_node_recur(head->link, num);
        }
    }
    return head;
}

void reverse_linked_list(struct node* head, struct node** ref)
{
    struct node* curr_next = NULL;

    if(head) {
        if(head->link == NULL) {
            *ref = head;
        } else {
            reverse_linked_list(head->link, ref);
            curr_next = head->link->link;
            head->link->link = head;
            head->link = curr_next;
        }
    }
}
