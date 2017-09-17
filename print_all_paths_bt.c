#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void insert_node_to_bst(struct node**, int);
void print_inorder_bst(struct node*);
void print_all_paths_to_leaf(struct node* root);
void print_path_to_leaf(struct node* root, int *path, int pathlen);
void print_complete_path(int *path, int pathlen);

int main()
{
    int num;
    struct node* root = NULL;

    while(1) {
        printf("Enter number to be added to bst:");
        scanf("%d",&num);

        if(num == -1) {
            break;
        } else {
            insert_node_to_bst(&root, num);
        }
    }

    printf("\nDisplaying BST in Inorder form\n");
    print_inorder_bst(root);

    printf("\nPrinting all paths from root to all leaves\n");
    print_all_paths_to_leaf(root);

    printf("\n");
    return 0;
}

void insert_node_to_bst(struct node** root, int num)
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

void print_inorder_bst(struct node* root)
{
    if(root) {
        print_inorder_bst(root->left);
        printf("%d\t", root->data);
        print_inorder_bst(root->right);
    }
}

void print_all_paths_to_leaf(struct node* root)
{
    int path[1000];
    print_path_to_leaf(root, path, 0);
}

void print_path_to_leaf(struct node* root, int *path, int pathlen)
{
    if(root) {
        path[pathlen] =  root->data;
        pathlen++;
        if(root->left == NULL && root->right == NULL) {
            print_complete_path(path, pathlen);
        } else {
            print_path_to_leaf(root->left, path, pathlen);
            print_path_to_leaf(root->right, path, pathlen);
        }
    }
}

void print_complete_path(int *path, int pathlen)
{
    int i = 0;

    for(i = 0; i < pathlen; i++) {
        printf("%d\t", path[i]);
    }
    printf("\n");
}
