#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct stack_node
{
    struct node* new_node;
    struct stack_node* next;
}*top = NULL;

struct node* insert_bst(struct node*, int);
void recursive_inorderbst(struct node*);
void push(struct stack_node**, struct node*);
struct node* pop(struct stack_node**);
int stack_empty(struct stack_node*);
void print_tree_top_view(struct node*);

int main ()
{
    int num;

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
 
    printf("\nTree Top View\n");
    print_tree_top_view(root);
    
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

void print_tree_top_view(struct node* root)
{
    struct node* temp_node = NULL;

    while(root->left) {
        push(&top, root);
        root = root->left;
    }
    printf("%d\t", root->data);

    while(!stack_empty(top)) {
        temp_node = pop(&top);
        printf("%d\t", temp_node->data);
    }

    if(temp_node) {
        root = temp_node;
    }

    while(root->right) {
        root = root->right;
        printf("%d\t", root->data);
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

int stack_empty(struct stack_node* top)
{
    if(!top) {
       return 1;
    } else {
       return 0;
    }
} 

void push(struct stack_node** top, struct node* root)
{
    struct stack_node* temp_node = NULL;
    temp_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    temp_node->next = NULL;
    temp_node->new_node = root;

    if(*top == NULL) {
        *top = temp_node;
    } else {
        temp_node->next = *top;
        *top = temp_node;
    }
}

struct node* pop(struct stack_node** top)
{
    struct node* temp_node = NULL;

    if(*top) {
        temp_node = (*top)->new_node;
        (*top) = (*top)->next;
    }
    return temp_node;
}
