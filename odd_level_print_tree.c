#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void insert_bst(struct node**, int);
void inorder_bst(struct node*);
void odd_level_print_bst(struct node* root, int is_odd_level);

int main()
{
    int num;
    int height_tree;
    int dia_tree;
    struct node* root = NULL;
    
    while(1) {
        printf("Enter the number to be added to bst:");
        scanf("%d", &num);
        if(num != -1) {
            insert_bst(&root, num);
        } else {
            break;
        }
    }
    printf("Displaying BST in inorder\n");
    inorder_bst(root);

    printf("Displaying odd level nodes of BST\n");
    odd_level_print_bst(root, 1);


    return 0;
}

void inorder_bst(struct node* root)
{
    if(root) {
        inorder_bst(root->left);
        printf("%d\t", root->data);
        inorder_bst(root->right);
    }
}

void insert_bst(struct node** root, int num)
{
    struct node* new_node = NULL;
    struct node* tmp_root = NULL;
    struct node* parent = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->left = NULL;
    new_node->right = NULL;

    if(*root == NULL) {
        *root = new_node;
    } else {
        tmp_root = *root;

        while(tmp_root) {
            parent = tmp_root;
            if(tmp_root->data < num) {
                tmp_root = tmp_root->right;
            } else {
                tmp_root = tmp_root->left;
            }
        }
        if(parent->data < num) {
            parent->right = new_node;
        } else {
            parent->left = new_node;
        }
    }
}

void odd_level_print_bst(struct node* root, int is_odd_level)
{
    if(root) {
        if(is_odd_level) {
            printf("%d\t", root->data);
        }
        odd_level_print_bst(root->left, !is_odd_level);
        odd_level_print_bst(root->right, !is_odd_level);
    }
}
