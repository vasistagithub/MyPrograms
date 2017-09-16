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
int get_height_tree(struct node*);
int get_diameter_tree(struct node*);
int max(int, int);

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

    printf("\nFinding the diameter of tree\n");

    height_tree = get_height_tree(root);
    printf("Height of given BST is %d\n", height_tree);

    dia_tree = get_diameter_tree(root);
    printf("Diameter of given BST is %d\n", dia_tree);

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

int get_height_tree(struct node* root)
{
    if(root == NULL) {
        return 0;
    } else {
        return 1 + max(get_height_tree(root->left), get_height_tree(root->right));
    }
}

int max(int a, int b)
{
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int get_diameter_tree(struct node* root)
{
    int lheight = 0;
    int rheight = 0;

    if(root == NULL) {
        return 0;
    } else {
        lheight = get_height_tree(root->left);
        rheight = get_height_tree(root->right);

        return (max(( 1 + lheight + rheight), max(get_diameter_tree(root->left), get_diameter_tree(root->right))));
    }
}
