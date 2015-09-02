/*Program to perform stack operations on linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
}*top = NULL;

void push(int);
int pop();
int stack_empty();

int main() 
{
	int num;

	while(1) {
		printf("Enter the node to be pushed into stack:");
		scanf("%d",&num);

		if(num==-1) {
			break;
		} else {
			push(num);
		}
	}

	printf("Printing contents of the stack\n");

	while(!stack_empty()) {
		printf("%d---",pop());
	}

	
	return 0;
}

void push(int num)
{
	struct node* new_node;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->link = NULL;


	if(top == NULL) {
		top = new_node;
	} else {
		new_node->link = top;
		top = new_node;
	}
}

int pop()
{
	int return_data = -1;

	if(top) {
		return_data = top->data;
		top = top->link;
	}
	return return_data;
}

int stack_empty()
{
	if(!top) {
		return 1;
	} else {
		return 0;
	}
}
