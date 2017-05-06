#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct sll
{
    struct node *val_sll;
    struct sll* next;
}*front = NULL, *rear = NULL;

struct node* insert_bst(struct node*, int);
void recursive_inorderbst(struct node*);
void LevelOrder(struct node* root);
int height_bst (struct node* root);
int max(int, int);
void print_level_order_bst_recursive (struct node* root, int height);
void print_each_level(struct node*, int);

void enqueue(struct node* val)
{
    struct sll *temp = NULL;
    temp = (struct sll*)malloc(sizeof(struct sll));
    temp->val_sll = val;
    temp->next = NULL;

    if(front == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

struct node* dequeue()
{
    struct sll* temp = NULL;

    if(front) {
        temp = front;
        front = front->next;
    }    
    return temp->val_sll;
}
int queue_empty()
{
    if(front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void LevelOrder(struct node* root)
{
    struct node* temp = NULL;

    if(root) {
        enqueue(root);
    }
    while(!queue_empty()) {
        temp = dequeue();
        printf("%d\t", temp->data);
        if(temp->left) {
            enqueue(temp->left);
        }
        if(temp->right) {
            enqueue(temp->right);
        }

    }
}

int main ()
{
    int num;
    int height = 0;

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

    height = height_bst(root);
    printf("\nHeight of the tree is %d\n", height);

    printf("\nLevel order traversal of tree\n");
    LevelOrder(root);
    
    printf("\n Level order traversal recursively\n");
    print_level_order_bst_recursive (root, height);

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

int height_bst (struct node* root)
{
    if(root == NULL) {
        return 0;
    } else {
        return 1 + max(height_bst(root->left), height_bst(root->right));
    }
}

int max(int a, int b)
{
    if (a >= b) {
         return a;
    } else {
        return b;
    }
}

void print_level_order_bst_recursive (struct node* root, int height)
{
    int i = 0;
    
    for(i=0; i<height; i++) {
        print_each_level(root, i+1);
    }
}

void print_each_level (struct node* root, int level)
{
    if(root == NULL) {
        return;
    } else {
        if(level == 1) {
            printf("%d\t", root->data);
        }
        print_each_level(root->left, level-1);
        print_each_level(root->right, level-1);
    }
}
