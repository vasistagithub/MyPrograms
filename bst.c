/*
 *Program to perform operations on Binary Search tree
 Author: Vasista Jayanth K
Date: September 3rd 2015
 * */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

void insert_bst(struct node**,int);
void inorder_bst(struct node*);

int main()
{
    int node_value;

    while(1) {
        printf("Enter the number to be inserted into BST:");
        scanf("%d",&node_value);
        if(node_value!= -1) {
            insert_bst(&root, node_value);
        } else {
            break;
        }

    }
    printf("Displaying BST in inorder fashion\n");
    inorder_bst(root);

    return 0;
}

void insert_bst(struct node** root, int node_value)
{
    struct node* temp;
    struct node* root_temp;
    struct node* parent;
    
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = node_value;
    temp->left = NULL;
    temp->right = NULL;

    root_temp = *root;

    if(!root_temp) {
        *root = temp;
    } else {
        while(root_temp) {
            parent = root_temp;
            if(root_temp->data <= node_value) {
                root_temp = root_temp->right;
            } else {
                root_temp = root_temp->left;
            }
        }
        if(parent->data > node_value) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    }
}

void inorder_bst(struct node* root)
{
    if(root) {
        inorder_bst(root->left);
        printf("%d---",root->data);
        inorder_bst(root->right);
    }
}
