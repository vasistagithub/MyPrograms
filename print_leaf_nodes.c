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
void print_leaf_nodes(struct node*);

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
    
    printf("\n Printing leaf nodes of BST\n");
    print_leaf_nodes(root);

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

void print_leaf_nodes(struct node* root)
{
    if(root)
    {
        if(root->left == NULL && root->right == NULL) {
            printf("%d\t", root->data);
        }
        print_leaf_nodes(root->left);
        print_leaf_nodes(root->right);
    }
}
