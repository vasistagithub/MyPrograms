#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct node* insert_bst(struct node*, int);

void print_left_sub_tree(struct node* root)
{
    if(root) {
        if(root->left) {
            printf("%d--", root->data);
            print_left_sub_tree(root->left);
        } else if (root->right) {
            printf("%d--", root->data);
            print_left_sub_tree(root->right);
        }
    }
}

void print_right_sub_tree(struct node* root)
{
    if(root) {
        if(root->right) {
            print_right_sub_tree(root->right);
            printf("%d--", root->data);
        } else if (root->left) {
            print_right_sub_tree(root->right);
            printf("%d--", root->data);
        }
    }
}

void print_all_leaves(struct node* root)
{
    if(root) {
        print_all_leaves(root->left);
        if(root->left == NULL && root->right == NULL) {
            printf("%d--", root->data);
        }
        print_all_leaves(root->right);
    }
}

void boundary_traversal(struct node* root)
{
    if(root) {
        printf("%d--", root->data);

        print_left_sub_tree(root->left);

        print_all_leaves(root->left);
        print_all_leaves(root->right);

        print_right_sub_tree(root->right);
    }
}

void display_inorder(struct node* root)
{
    if(root) {
        display_inorder(root->left);
        printf("%d--", root->data);
        display_inorder(root->right);
    }
}

int main ()
{
    int num;

    while(1) {
        printf("Enter the number(To Stop press -1):");
        scanf("%d", &num);

        if(num == -1) {
            break;
        } else {
            root = insert_bst(root, num);
        }
    }

    printf("Displaying tree in Inorder form\n");
    display_inorder(root);

    printf("\nDisplaying boundaries of given BST\n");
    boundary_traversal(root);
     
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
