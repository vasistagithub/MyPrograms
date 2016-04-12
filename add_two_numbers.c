#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void insert_list(struct ListNode**,int);
void display_list(struct ListNode*);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

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
    printf("Displaying list-2\n");
    display_list(l2);
    
    printf("Summing two SLL\n");
    l3 = addTwoNumbers(l1,l2);
    
    printf("Displaying list-3\n");
    display_list(l3);

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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry_fw = 0;
    int sum = 0;
    struct ListNode *l3 = NULL;

    while(l1 && l2) {
        sum = carry_fw + l1->val + l2->val;
        carry_fw = sum/10;
        insert_list(&l3,sum%10);
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL) {
        sum = carry_fw + l1->val;
        carry_fw = sum/10;
        insert_list(&l3,sum%10);
        l1 = l1->next;

    } 
    while(l2 != NULL) {
        
        sum = carry_fw + l2->val;
        carry_fw = sum/10;
        insert_list(&l3, sum%10);
        l2 = l2->next;
    }
    
    if(carry_fw) {
        insert_list(&l3, carry_fw);
    }
    return l3;
}    
