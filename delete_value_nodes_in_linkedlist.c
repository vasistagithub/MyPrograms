#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* create_node (int val)
{
    struct node* tmp_node = NULL;

    tmp_node = (struct node*)malloc(sizeof(struct node));
    tmp_node->data = val;
    tmp_node->next = NULL;

    return tmp_node;
}

void insert_linkedlist (struct node** head, int num)
{
    struct node* tmp_node = NULL;
    struct node* tmp_head = NULL;

    if(head == NULL) {
        return;
    } else {
        tmp_node = create_node(num);

        if(*head == NULL) {
            *head = tmp_node;
        } else {
            tmp_head = *head;
            while(tmp_head->next) {
                tmp_head = tmp_head->next;
            }
            tmp_head->next = tmp_node;
        }
    }
}

void display_linkedlist (struct node* head)
{
    while(head) {
        printf("%d\t", head->data);
        head = head->next;
    }
}

int duplicate_linkedlist (struct node* head1, struct node** head2)
{
    int length_linkedlist = 0;
    struct node* tmp_node = NULL;
    struct node* tmp_head = NULL;

    if(head2 == NULL) {
        return;
    } else {
        while(head1) {
            tmp_node = create_node(head1->data);
            if(*head2 == NULL) {
                *head2 = tmp_node;
            } else {
                tmp_head = *head2;
                while(tmp_head->next) {
                    tmp_head = tmp_head->next;
                }
                tmp_head->next = tmp_node;
            }
            length_linkedlist++;
            head1 = head1->next;
        }
    }
    return length_linkedlist;
}

void delete_linkedlist (struct node** head, int val)
{
    struct node* parent = NULL;
    struct node* tmp_head = NULL;

    if(!head || !(*head)) {
        printf("Passed in parameter is NULL\n");
        return;
    } else {
        if((*head)->data == val) {
            (*head) = (*head)->next;
        } else {
            parent = tmp_head = *head;
            tmp_head = tmp_head->next;
            while(tmp_head) {
                if(tmp_head->data == val) {
                    break;
                }
                parent = tmp_head;
                tmp_head = tmp_head->next;
            }
            if(tmp_head) {
                parent->next = tmp_head->next;
            } else {
                parent->next = NULL;
            }
        }    
    }
}

void update_linkedlist (struct node **head1, struct node* head2, 
                       int length_linkedlist)
{
    int num_to_delete;
    int count = 0;
    struct node* tmp_head = head2;
    struct node* current = NULL;
    
    while(head2) {
        current = head2;
        if(head2->data > length_linkedlist) {
            break;
        } else {
            count = head2->data;
            head2 = tmp_head;
            while(count > 1) {
                count--;
                head2 = head2->next;
            }
            num_to_delete = head2->data;
            printf("\nNum to delete is %d\n", num_to_delete);
            head2 = current;
            delete_linkedlist(head1, num_to_delete);
        }
        head2 = head2->next;
    }
}

void delete_value_nodes_in_linkedlist (struct node** head)
{
    struct node* head2 = NULL;
    int length_linkedlist = 0;

    if(!head || !(*head)) {
        return;
    } else {
        length_linkedlist = duplicate_linkedlist(*head, &head2);        

        update_linkedlist(head, head2, length_linkedlist);
    }
}

int main ()
{
    struct node* head = NULL;
    int num;

    while(1) {
        printf("Enter num to be added to linkedlist:");
        scanf("%d",&num);

        if(num == -1) {
            break;
        } else {
            insert_linkedlist(&head, num);
        }
    }

    printf("\nDisplaying current linkedlist\n");
    display_linkedlist(head);
    
    printf("\n Delete value nodes from linkedlist\n");

    delete_value_nodes_in_linkedlist(&head);

    printf("\nDisplaying updated linkedlist after value nodes removal\n");
    display_linkedlist(head);

    printf("\n"); 
    
    return 0;

}
