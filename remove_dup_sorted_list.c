#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

void insert_list(struct ListNode**,int);
void display_list(struct ListNode*);
struct ListNode* deleteDuplicates(struct ListNode* head);

int main()
{
    int num;
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    while(1) {
        printf("Enter the num in sorted order(To stop press -1):");
        scanf("%d",&num);
        if(num!=-1) {
            insert_list(&l1,num);
        } else {
            break;
        }
    }

    printf("Display elements in the list\n");
    display_list(l1);

    l2 = deleteDuplicates(l1);

    printf("Display elements in the list\n");
    display_list(l2);

    return 0;
}

void insert_list(struct ListNode** list, int num)
{
    struct ListNode* tmp;
    
    struct ListNode* new_node;
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = num;
    new_node->next = NULL;
    
    tmp = *list;

    if(tmp == NULL) {
        *list = new_node;
    } else {
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

void display_list(struct ListNode* list)
{
    while(list) {
        printf("%d\t", list->val);
        list = list->next;
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* tmp_head = NULL;
    struct ListNode* parent_node = NULL;
    struct ListNode* next_node = NULL;
    int count = 0;

    tmp_head = head;

    while(tmp_head) {
        next_node = tmp_head->next;
        parent_node = NULL;
        count = 0;

        while(next_node && next_node->val == tmp_head->val) {
            count++;
            parent_node = next_node;
            next_node = next_node->next;
        }

        if(count) {
            tmp_head->next = parent_node->next;
            tmp_head = parent_node;
        } else{
            tmp_head = tmp_head->next;
        }
    }

    return head;
}
