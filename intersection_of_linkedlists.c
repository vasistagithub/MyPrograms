#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head = NULL;

void display_linkedlist(struct node* head)
{
    while(head) {
        printf("%d--", head->data);
        head = head->next;
    }
}

int get_linked_list_size(struct node* head)
{
    int count = 0;

    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

struct node* intersection_linkedlists(struct node* head1, struct node* head2)
{
    int length_list1, length_list2, diff;

    length_list1 = get_linked_list_size(head1);
    length_list2= get_linked_list_size(head2);

    diff = length_list1 - length_list2;

    if(diff > 0) {
        while(diff) {
            head1 = head1->next;
            diff--;
        }
    } else {
        diff = diff*-1;
        while(diff) {
            head2 = head2->next;
            diff--;
        }
    }
    while(head1 && head2) {
        if(head1->data == head2->data) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}


int main()
{
    /*
     *     Create two linked lists
     *      
     *     1st 3->6->9->15->30
     *     2nd 10->15->30
     *         
     *     15 is the intersection point
     */

    struct node* newnode;
    struct node* head1 =
        (struct node*) malloc(sizeof(struct node));
    head1->data  = 10;

    struct node* head2 =
        (struct node*) malloc(sizeof(struct node));
    head2->data  = 3;

    newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = 6;
    head2->next = newnode;

    newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = 9;
    head2->next->next = newnode;

    newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = 15;
    head1->next = newnode;
    head2->next->next->next  = newnode;

    newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = 30;
    head1->next->next= newnode;

    head1->next->next->next = NULL;

    printf("Displaying List1\n");
    display_linkedlist(head1);
    
    printf("\nDisplaying List2\n");
    display_linkedlist(head2);

    printf("Checking whether intersection is present among two linkedlists\n");

    struct node* ptr = intersection_linkedlists(head1, head2);
    
    if(ptr == NULL) {
        printf("\n No intersection found among two linkedlists\n");
    } else {
        printf("\n Intersection found among two linkedlists at %p and val is %d\n",
               ptr, ptr->data);
    }

    return 0;
}
