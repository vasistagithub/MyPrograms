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
void recursive_preorderbst(struct node*);
void recursive_inorderbst(struct node*);
void recursive_postorderbst(struct node*);
void push(struct stack_node**, struct node*);
struct node* pop(struct stack_node**);
int stack_empty(struct stack_node*);
void iterative_preorder(struct node*);
void iterative_inorder(struct node*);
void iterative_postorder(struct node*);

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
    printf("\nDisplaying BST in preorder(Recursive)\n");
    recursive_preorderbst(root);
    printf("\nDisplaying BST in inorder(Recursive)\n");
    recursive_inorderbst(root);
    printf("\nDisplaying BST in postorder(Recursive)\n");
    recursive_postorderbst(root);

    printf("\nIterative preorder BST\n");
    iterative_preorder(root);
   
    printf("\nIterative Inorder BST\n");
    iterative_inorder(root);
    
    printf("\nIterative postorder BST\n");
    iterative_postorder(root);
    
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

void recursive_preorderbst(struct node* root)
{
    if(root) {
        printf("%d\t", root->data);
        recursive_preorderbst(root->left);
        recursive_preorderbst(root->right);
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

void recursive_postorderbst(struct node* root)
{
    if(root) {
        recursive_postorderbst(root->left);
        recursive_postorderbst(root->right);
        printf("%d\t", root->data);
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

void iterative_preorder(struct node* root)
{
    struct node* temp_node = NULL;
    if(root) {
        push(&top, root);
        while(!stack_empty(top)) {
            temp_node = pop(&top);
            printf("%d\t", temp_node->data);
            if(temp_node->right) {
                push(&top, temp_node->right);
            }
            if(temp_node->left) {
                push(&top, temp_node->left);
            }
        }
    }
}

void iterative_inorder(struct node* root)
{
    struct node* temp_node = NULL;
    struct node* temp_right = NULL;

    if(root) {
        push(&top, root);
        while(root->left) {
            root = root->left;
            push(&top, root);
        }
        while(!stack_empty(top)) {
            temp_node = pop(&top);
            printf("%d\t", temp_node->data);
            if(temp_node->right) {
                push(&top, temp_node->right);
                temp_right = temp_node->right;
                while(temp_right->left) {
                    push(&top, temp_right->left);
                }
            }
        }
    }
}

void iterative_postorder(struct node* root)
{
    struct node* temp_node = NULL;
    struct node* temp_right = NULL;

    while(root) {
        if(root->right) {
            push(&top, root->right);
        }
        push(&top, root);
        root = root->left;
    }
    while(!stack_empty(top)) {
        temp_node = pop(&top);
        if(temp_node->right) {
            if(top && (top->new_node->data == temp_node->right->data)) {
                temp_right = pop(&top);
                push(&top, temp_node);
                temp_node = temp_node->right;
                while(temp_node) {
                    if(temp_node->right) {
                        push(&top, temp_node->right);
                    }
                    push(&top, temp_node);
                    temp_node = temp_node->left;
                }
            } else {
                printf("%d\t", temp_node->data);
            }
        } else {
            printf("%d\t", temp_node->data);
        }
    }
}
