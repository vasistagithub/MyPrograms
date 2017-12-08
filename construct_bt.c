#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* construct_tree(int first, int last, int *in, int *pre);
void postorder(struct node*);
void inorder(struct node*);
int search_inorder(int *array, int num, int first, int last);

int main()
{
    int num_nodes;
    int *in = NULL;
    int *pre = NULL;
    int i;
    int vertex;
    struct node* root = NULL;

    printf("Enter number of nodes in a Binary Tree:");
    scanf("%d", &num_nodes);

    in = (int*)malloc(num_nodes * sizeof(int));
    pre = (int*)malloc(num_nodes * sizeof(int));

    printf("Input tree nodes in Inorder form\n");
    for(i = 0; i < num_nodes; i++) {
        printf("Enter %d vertex:", i);
        scanf("%d", &vertex);
        in[i] = vertex;
    }

    printf("Input tree nodes in preorder form\n");
    for(i = 0; i < num_nodes; i++) {
        printf("Enter %d vertex:", i);
        scanf("%d", &vertex);
        pre[i] = vertex;
    }

    root = construct_tree(0, num_nodes-1, in, pre);

    printf("printing Binary tree in Post order form\n");
    postorder(root);

    printf("\n");

    printf("printing Binary tree in In order form\n");
    inorder(root);

    printf("\n");


    return 0;
}

void postorder(struct node* root)
{
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d--", root->data);
    }
}

void inorder(struct node* root)
{
    if(root) {
        inorder(root->left);
        printf("%d--", root->data);
        inorder(root->right);
    }
}

int search_inorder(int *array, int num, int first, int last)
{
    int i;
    for(i = first; i <=last; i++) {
        if(array[i] == num) {
            return i;
        }
    }
    return -1;
}

struct node* construct_tree(int first, int last, int *in, int *pre)
{
    static int current = 0;
    struct node* tmp_node = NULL;
    int root_loc;
    int root_value;

    if(first > last) {
       return NULL;
    } else {
        tmp_node = (struct node*)malloc(sizeof(struct node));
        tmp_node->data = pre[current++];
        tmp_node->left = NULL;
        tmp_node->right = NULL;

        root_loc = search_inorder(in, tmp_node->data, first, last);

        if(root_loc == -1) {
            return NULL;
        }
        tmp_node->left = construct_tree(first, root_loc-1, in, pre);
        tmp_node->right = construct_tree(root_loc+1, last, in, pre);

        return tmp_node;
    }
}


