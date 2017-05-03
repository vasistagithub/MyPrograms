#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct sll
{
    struct node* val_node;
    struct sll* next;
}*top1 = NULL, *top2 = NULL;

struct node* insert_bst(struct node*, int);
void recursive_inorderbst(struct node*);
struct node* lca(struct node*, int, int);

int main ()
{
    int num;
    int node1, node2;
    struct node* new_node = NULL;

    while(1) {
        printf("Enter the number:");
        scanf("%d", &num);

        if(num == -1) {
            break;
        } else {
            root = insert_bst(root, num);
        }
    }
    printf("\nDisplaying BST in inorder(Recursive)\n");
    recursive_inorderbst(root);

    printf("Enter first node in BST:");
    scanf("%d",&node1);
    
    printf("Enter second node in BST:");
    scanf("%d",&node2);
    
    printf("\nFind lowest common ancestor of two nodes in BST\n");
    new_node = lca(root, node1, node2);
   
    if(new_node) { 
        printf("Lowest common ancestor of %d and %d is %d\n",
               node1, node2, new_node->data);
    }
    printf("\n");

    return 0;
}

struct node* insert_bst(struct node *root, int num)
{
    struct node* temp_node = NULL;
    struct node* temp_root = root;
    struct node* parent = NULL;

    temp_node = (struct node*)malloc(sizeof(struct node));
    temp_node->data = num;
    temp_node->left = NULL;
    temp_node->right = NULL;

    if(root == NULL) {
        return temp_node;
    } else {
        while(temp_root) {
            parent = temp_root;
            if(temp_root->data >= num) {
                temp_root = temp_root->left;
            } else {
                temp_root = temp_root->right;
            }
        }
        if(parent->data <= num) {
            parent->right = temp_node;
        } else {
            parent->left = temp_node;
        }
        return root;
    }
}

void recursive_inorderbst(struct node* root)
{
    if(root) {
        recursive_inorderbst(root->left);
        printf("%d\t", root->data);
        recursive_inorderbst(root->right);
    }
}

void push_stack(struct sll **top, struct node *new_node)
{
    struct sll *temp_node = NULL;
    temp_node = (struct sll*)malloc(sizeof(struct sll));
    temp_node->val_node = new_node;
    temp_node->next = NULL;

    if(*top == NULL) {
        (*top) = temp_node;
    } else {
        temp_node->next = (*top);
        (*top) = temp_node;
    }
}

struct node* lca(struct node *root, int v1,int v2)
{
    struct node *temp = NULL;
    struct node *parent = NULL;
    int stack1_length = 0;
    int stack2_length = 0;
    int first_stack_big = 0;

    temp = root;
    while(temp) {
        parent = temp;
        push_stack(&top1, parent);
        stack1_length++;

        if(parent->data == v1) {
            break;
        }

        if(v1 <= temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    temp = root;
    while(temp) {
        parent = temp;

        push_stack(&top2, parent);
        stack2_length++;

        if(parent->data == v2) {
            break;
        }
        if(v2 <= temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    if(!stack1_length || !stack2_length) {
        return root;
    }
    if(stack1_length >= stack2_length) {
        first_stack_big = 1;
    }
    if(first_stack_big) {
        while(stack1_length > stack2_length) {
            top1 = top1->next;
            stack1_length--;
        }
    } else {
        while(stack2_length > stack1_length) {
            top2 = top2->next;
            stack2_length--;
        }
    }

    while(top1 && top2) {
        if(top1->val_node->data == top2->val_node->data) {
            break;
        } else {
            top1 = top1->next;
            top2 = top2->next;
        }
    }
    return top1->val_node;
}
