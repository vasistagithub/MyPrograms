#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head = NULL;

struct node* insert_linkedlist(struct node* head, int num);
void display_linkedlist(struct node*);
int palindrome_list(struct node** list1, struct node* list2);

int main()
{
    int num;

    while(1) {
        printf("Enter the number:");
        scanf("%d",&num);

        if(num == -1) {
            break;
        } else {
            head = insert_linkedlist(head, num);
        }
    }

    printf("Displaying Linked list\n");
    display_linkedlist(head);

    printf("\n");

    printf("Verifying whether given linked list is palindrome or not\n");

    if(palindrome_list(&head, head)) {
        printf("Given Linked list is palindrome\n");
    } else {
        printf("Given Linked list is not palindrome\n");
    }

    return 0;

}

struct node* insert_linkedlist(struct node* head, int num)
{

    if(head == NULL) {
        struct node* tmp_node = NULL;
        tmp_node = (struct node*)malloc(sizeof(struct node));
        tmp_node->data = num;
        tmp_node->next = NULL;

        return tmp_node;
    } else {
        head->next = insert_linkedlist(head->next, num);
        return head;
    }
}

void display_linkedlist(struct node* head)
{
    while(head) {
        printf("%d--", head->data);
        head = head->next;
    }
}

int palindrome_list(struct node** list1, struct node* list2)
{
    int flag = 1;

    if(list2 != NULL) {
        flag = palindrome_list(list1, list2->next);
        if(flag == 0) {
            return flag;
        } else {
           if((*list1)->data != list2->data) {
                flag = 0;
                return flag;
           } else {
               (*list1) =  (*list1)->next;
           }
        }
    }
    return flag;
}
