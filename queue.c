/*Program to perform queue operations*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int);
void dequeue(int);
void display_queue();

int main()
{
	int num;

	while(1) {
		printf("Enter the number to be added to queue:");
		scanf("%d", &num);

		if(num == -1) {
			break;
		} else {
			enqueue(num);
		}
	}

	printf("Displaying elements in the queue\n");
	display_queue();

	printf("Enter the number to be dequeued:");
	scanf("%d", &num);

	dequeue(num);

	printf("Queue elements after dequeue are\n");
	display_queue();

	return 0;
}

void enqueue(int num)
{
	struct node* new_node;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->link = NULL;

	if(front == rear && front == NULL) {
		front = rear = new_node;
	} else {
		rear->link = new_node;
		rear = new_node;
	}
}

void display_queue(struct node* temp)
{
	temp = front;
	while(temp) {
		printf("%d----", temp->data);
		temp = temp->link;
	}
}

void dequeue(int num)
{
	struct node* temp;
	struct node* parent;

	temp = front;

	if(temp && temp->data == num) {
		front = temp->link;
	} else {
		while(temp && temp->data != num) {
			parent = temp;	
			temp = temp->link;
		}

		if(temp) {
			parent->link = temp->link;
		} else {
			printf("%d not found in queue\n", num);
		}
	}
}
