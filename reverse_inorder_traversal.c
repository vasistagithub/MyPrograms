#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;

void reverse_inorder_traversal(struct node*);
struct node* insert_bst(struct node*, int);

int main()
{
    int num;
    
    while(1) {
        printf("Enter number to be added to BST:");
        scanf("%d",&num);

        if(num == -1) {
            break;
        } else {
            root=insert_bst(root, num);
        }
    }

    printf("Printing Tree in Reverse Inorder Traversal Form\n");
    reverse_inorder_traversal(root);

    return 0;
}

void reverse_inorder_traversal(struct node* root)
{
    if(root) {
        reverse_inorder_traversal(root->right);
        printf("%d\t", root->data);
        reverse_inorder_traversal(root->left);
    }
}

struct node* insert_bst(struct node* root, int num)
{
    struct node* tmp_node = NULL;
    struct node* parent = NULL;
    struct node* tmp_root = NULL;


    tmp_node = (struct node*)malloc(sizeof(struct node));
    tmp_node->data = num;
    tmp_node->left = NULL;
    tmp_node->right = NULL;
    
    if(root == NULL) {
        return tmp_node;
    } else {
        tmp_root = root;
        while(tmp_root) {
            parent = tmp_root;
            if(tmp_root->data > num) {
                tmp_root=tmp_root->left;
            } else {
                tmp_root=tmp_root->right;
            }
        }
        if(parent->data > num) {
            parent->left = tmp_node;
        } else {
            parent->right = tmp_node;
        }
        return root;
    }
}
