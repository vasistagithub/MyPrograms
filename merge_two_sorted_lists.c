#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void insert_list(struct ListNode**,int);
void display_list(struct ListNode*);

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
struct ListNode* mergeTwoLists_v2(struct ListNode* l1, struct ListNode* l2);
void insert_list_v2(struct ListNode** ret_list, struct ListNode* list);

int main()
{
    struct ListNode *l1 = NULL, *l2 = NULL;
    int num;
    struct ListNode *l3 = NULL;

    printf("Enter elements for first list(to stop press -1)\n");
    while(1) {
        scanf("%d",&num);
        if(num == -1) {
            break;
        } else {
            insert_list(&l1, num);
        }
    }

    printf("Enter elements for second list(to stop press -1)\n");
    while(1) {
        scanf("%d",&num);
        if(num == -1) {
            break;
        } else {
            insert_list(&l2, num);
        }
    }

    printf("Displaying list-1\n");
    display_list(l1);
    printf("\nDisplaying list-2\n");
    display_list(l2);
    
    printf("\nMerging two sorted SLL\n");
    l3 = mergeTwoLists(l1,l2);
    
    printf("Displaying list-3\n");
    display_list(l3);
    
    printf("\n");

    printf("Merging two sorted SLL Version2\n");
    l3 = mergeTwoLists_v2(l1,l2);
    
    printf("Displaying list-3\n");
    display_list(l3);

    printf("\n");
    
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* l3 = NULL;

    while(l1 && l2) {
        if(l1->val <= l2->val) {
            insert_list(&l3,l1->val);
            l1 = l1->next;
        } else {
            insert_list(&l3,l2->val);
            l2 = l2->next;
        }
    }
    if(l1 == NULL) {
        while(l2) {
            insert_list(&l3, l2->val);
            l2 = l2->next;
        }
    }
    if(l2 == NULL) {
        while(l1) {
            insert_list(&l3,l1->val);
            l1 = l1->next;
        }
    }

    return l3;
}

/* This function wont use extra memory for all nodes to create list3.
 * Instead, it just links the pointers from list 1 and list2 to make
 * a sorted list3 
 */
struct ListNode* mergeTwoLists_v2(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* l3 = NULL;
    struct ListNode* tmp_node = NULL;

    while(l1 && l2) {
        if(l1->val <= l2->val) {
            tmp_node = l1->next;
            insert_list_v2(&l3,l1);
            l1 = tmp_node;
        } else {
            tmp_node = l2->next;
            insert_list_v2(&l3,l2);
            l2 = tmp_node;
        }
    }
    if(l1 == NULL) {
        while(l2) {
            tmp_node = l2->next;
            insert_list_v2(&l3, l2);
            l2 = tmp_node;
        }
    }
    if(l2 == NULL) {
        while(l1) {
            tmp_node = l1->next;
            insert_list_v2(&l3,l1);
            l1 = tmp_node;
        }
    }
    return l3;
}

void insert_list_v2(struct ListNode** ret_list, struct ListNode* list)
{
    struct ListNode* tmp_node = NULL;

    list->next = NULL;

    if(*ret_list == NULL) {
        *ret_list = list;
    } else {
        tmp_node = (*ret_list);
        while(tmp_node->next) {
            tmp_node = tmp_node->next;
        }
        tmp_node->next = list;
    }
}
