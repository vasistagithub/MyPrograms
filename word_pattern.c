#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};


int wordPattern(char *pattern, char* str);
void insert_list(struct ListNode** list, int num);
int traverse_list(struct ListNode*);
void display_list(struct ListNode*);

char **tok_str = NULL;

int main()
{
    char pattern[10];
    char str[1000];
    int ret_val = 0;

    memset(pattern,'\0',sizeof(pattern));
    memset(str,'\0',sizeof(str));
    printf("Enter the pattern:");
    //fgets(pattern,sizeof(pattern),stdin);
    gets(pattern);
    printf("Enter the string:");
    //fgets(str,sizeof(str),stdin);
    gets(str);
    ret_val = wordPattern(pattern,str);

    if(ret_val) {
        printf("string matches with pattern\n");
    } else {
        printf("string doesn't match with pattern\n");
    }
    return 0;
}

int wordPattern(char *pattern, char* str)
{
    struct ListNode *alpha[26];
    struct ListNode *first = NULL;
    struct ListNode *second = NULL;
    int i;
    int len_pattern;
    int ret_val = 1;
    int len_token = 0;
    char *token;
    int index = 0;
    len_pattern = strlen(pattern);

    for(i=0;i<26;i++) {
        alpha[i] = NULL;
    }
    for(i=0;i<len_pattern;i++) {
        insert_list(&alpha[pattern[i]-'a'],i);
    }

    tok_str = (char**)calloc(len_pattern,sizeof(char*));
   
    token = strtok(str," ");
    len_token = strlen(token);
    tok_str[index++] = (char*)calloc(len_token+1,sizeof(char));
    strcpy(tok_str[index-1],token);

    while(token) {
        token = strtok(NULL, " ");
        if(token) {
            len_token = strlen(token);
            tok_str[index++] = (char*)calloc(len_token+1,sizeof(char));
            strcpy(tok_str[index-1],token);
        }
    }

    if(index != len_pattern) {
        return 0;
    }
   for(i=0;i<index;i++) {
      printf("token is %s\n",tok_str[i]);
   } 
    for(i=0;i<26;i++) {
        if(alpha[i]) {
            display_list(alpha[i]);
            printf("\n");
        }
    }
    for(i=0;i<26;i++) {
        if(alpha[i]) {
            if(!first) {
                first = alpha[i];
            }else {
                second = alpha[i];
            }
            if(first && second) {
                if(!strcmp(tok_str[first->val],tok_str[second->val])) {
                    return 0;
                }
                first = second;
                second = NULL;

            }
        }
    }
         
    for(i=0;i<26;i++) {
    ret_val = ret_val && traverse_list(alpha[i]);
   } 
 
    return ret_val;
}

void display_list(struct ListNode *root)
{
    while(root) {
        printf("%d\t",root->val);
        root = root->next;
    }
}

void insert_list(struct ListNode** list, int num)
{
    struct ListNode* tmp;
    
    struct ListNode* new_node;
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = num;
    new_node->next = NULL;
    
    tmp = *list;

    if(tmp == NULL) {
        *list = new_node;
    } else {
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

int traverse_list(struct ListNode* list)
{
    char *str;
    str = (char*)calloc(100,sizeof(int));
    
    if(list) {
        str = tok_str[list->val];
        list = list->next;
    }
    while(list) {
        if(strcmp(str,tok_str[list->val])) {
           return 0;
        } 
        list = list->next;
    }
    return 1;
}
