#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void insert_list(struct ListNode**,int);
void display_list(struct ListNode*);

struct ListNode* swapPairs(struct ListNode* head);

int main()
{
    struct ListNode *l1 = NULL, *l2 = NULL;
    int num;

    printf("Enter elements for first list(to stop press -1)\n");
    while(1) {
        scanf("%d",&num);
        if(num == -1) {
            break;
        } else {
            insert_list(&l1, num);
        }
    }

    printf("Displaying the input list\n");
    display_list(l1);

    l2 = swapPairs(l1);

    printf("Displaying list after swap in pairs\n");
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

struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode* parent = NULL;
    struct ListNode* first = NULL;
    struct ListNode* second = NULL;

    if(head) {
        first = head;
        second = head->next;

        while(first && second) {
            if(parent == NULL) {
                first->next = second->next;
                second->next = first;
                head = second;
                parent = first;
                first = first->next;
            } else {
                first->next = second->next;
                second->next = first;
                parent->next = second;
                parent = first;
                first = first->next;
            }
           if(first) {
              second = first->next;
           } 
        }

        return head;
    }
}
