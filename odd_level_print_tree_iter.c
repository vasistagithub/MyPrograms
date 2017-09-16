#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct queue_node
{
    int is_odd_level;
    struct node* tree_node;
    struct queue_node* next;
};

struct queue_node* front = NULL;
struct queue_node* rear = NULL;

void insert_bst(struct node**, int);
void inorder_bst(struct node*);
void odd_level_print_bst(struct node*, int);
int queue_empty();
void enqueue(struct node*, int);
struct queue_node* dequeue();

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

    printf("\nDisplaying odd level nodes of BST\n");
    odd_level_print_bst(root, 1);

    printf("\n");
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

void enqueue(struct node* tree_node, int is_odd_level)
{
    struct queue_node * new_node = NULL;

    new_node = (struct queue_node*)malloc(sizeof(struct queue_node));
    new_node->tree_node = tree_node;
    new_node->is_odd_level = is_odd_level;
    new_node->next = NULL;

    if(front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int queue_empty()
{
    if(front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

struct queue_node* dequeue()
{
    struct queue_node* curr_node = NULL;

    if(front) {
        curr_node = front;
        front = front->next;
    }
    return curr_node;
}

void odd_level_print_bst(struct node* root, int is_odd_level)
{
    struct queue_node* curr_node = NULL;
    int level = -1;
    int prev_level = 0;
    int curr_level = 0;

    if(root) {   
        enqueue(root, is_odd_level);
       
        while(!queue_empty()) {
            curr_node = dequeue();
            if(prev_level != curr_node->is_odd_level && !prev_level) {
                if(level > 0) {
                    printf("\n");
                }
                level+=2;
                printf("Level is %d-->", level);
            }
            prev_level = curr_node->is_odd_level;
            
            if(curr_node->is_odd_level) {
                printf("%d\t", curr_node->tree_node->data);
            }
            if(curr_node->tree_node->left) {
                enqueue(curr_node->tree_node->left, !curr_node->is_odd_level);
            }
            if(curr_node->tree_node->right) {
                enqueue(curr_node->tree_node->right, !curr_node->is_odd_level);
            }
        }
    }
}
