#include <stdio.h>
#include <stdlib.h>

struct node 
{		int data;
    struct node* next;
}*head = NULL;

void display_sll(struct node* head)
{
    while(head) {
        printf("%d---", head->data);
        head = head->next;
    }
}

struct node* insert_sll(struct node* head, struct node* new_node)
{
    if(head == NULL) {
        return new_node;
    } else {
        head->next = insert_sll(head->next, new_node);
        return head;
    }
}

struct node* reverse_sll_internal(struct node* head, struct node** new_head)
{
    struct node* tmp_head = NULL;

    if(head->next == NULL) {
        if(*new_head == NULL) {
            *new_head = head;
        }
        return head;
    } else {
        tmp_head = reverse_sll_internal(head->next, new_head);
        tmp_head->next = head;
        head->next = NULL;
        return head;
    }
}

struct node* reverse_sll(struct node* head)
{
    struct node* new_head = NULL;

    if(head) {
        reverse_sll_internal(head, &new_head);
    }
    return new_head;
}

int main()
{
    int num;
    struct node* new_node = NULL;

    while(1) {
        printf("Enter the number to be added to list:");
        scanf("%d", &num);

        if(num == -1) {
            break;
        } else {

            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next = NULL;

            head = insert_sll(head, new_node);
        }
    }
    printf("\n Displaying Single Linked list\n");
    display_sll(head);

    printf("\n Reversing Single Linked List\n");
    head = reverse_sll(head);

    printf("\n Displaying Single Linked list after reversal\n");
    display_sll(head);

    return 0;
}

