#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void insert_list(struct ListNode**,int);
void display_list(struct ListNode*);

struct ListNode* removeNthFromEnd(struct ListNode*,int);

int main()
{
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    int num;
    int loc_end;

    printf("Enter elements for first list(to stop press -1)\n");
    while(1) {
        scanf("%d",&num);
        if(num == -1) {
            break;
        } else {
            insert_list(&l1, num);
        }
    }

    printf("Displaying list-1\n");
    display_list(l1);

    printf("Enter the location of node to be removed from end:");
    scanf("%d",&loc_end);

    l2 = removeNthFromEnd(l1,loc_end);     
    
    printf("Displaying list after node removal\n");
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode* l1 = head;
    int count = 0;
    int node_to_be_removed = 0;
    struct ListNode* tmp_head = NULL;
    struct ListNode* parent = NULL;

    if(l1) {
        while(l1) {
            l1 = l1->next;
            count++;
        }

        if(n > count) {
            return head;
        } else {
            node_to_be_removed = (count - n) + 1;
            printf("Location of node to be removed is %d\n",
                    node_to_be_removed);
        }
        if(node_to_be_removed == 1) {
            head = head->next;
        } else {
            tmp_head = head;
            node_to_be_removed--;
            while(tmp_head && node_to_be_removed) {
                parent = tmp_head;
                tmp_head = tmp_head->next;
                node_to_be_removed--;
            }
            parent->next = tmp_head->next;
        }
    }
    return head;
}
