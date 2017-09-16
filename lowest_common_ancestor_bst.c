#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct node* insert_bst(struct node*, int);
void recursive_inorderbst(struct node*);
struct node* lowest_common_ancestor_iter(struct node*, int, int);
int lowest_common_ancestor_recur(struct node*, int, int);

int main ()
{
    int num;
    int node1, node2;
    struct node* new_node = NULL;
    int ancestor_val = -1;

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
    
    printf("\nFind lowest common ancestor by iterative way in BST\n");
    new_node = lowest_common_ancestor_iter(root, node1, node2);
   
    if(new_node) { 
        printf("Lowest common ancestor of %d and %d is %d\n",
               node1, node2, new_node->data);
    } else {
        printf("Lowest common ancestor of %d and %d is not found\n",
               node1, node2);
    }

    printf("\nFinding lowest common ancestor by recursive way in BST\n");
    ancestor_val = lowest_common_ancestor_recur(root, node1, node2);
 
    if(ancestor_val == -1) {
        printf("No Lowest common ancestor of %d and %d found\n", node1, node2);
    } else {
        printf("Lowest common ancestor of %d and %d is %d\n", node1, node2, ancestor_val);
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

struct node* lowest_common_ancestor_iter(struct node* root, int n1, int n2)
{
    while(root) {
        if(root->data > n1 && root->data > n2) {
            root = root->left;
        } else if (root->data < n1 && root->data < n2) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}

int lowest_common_ancestor_recur(struct node* root, int n1, int n2)
{
    if(root == NULL) {
        return -1;
    }

    if(root->data > n1 && root->data > n2) {
        return lowest_common_ancestor_recur(root->left, n1, n2);
    }

    if(root->data < n1 && root->data < n2) {
        return lowest_common_ancestor_recur(root->right, n1, n2);
    }
    return root->data;
}
