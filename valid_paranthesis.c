#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define bool int
#define TRUE 1
#define FALSE 0

bool isValid(char*);
void push(char*,char);
char pop(char**);
bool stack_empty(char*);

int main()
{
    char *str;
    bool valid_paran = FALSE;

    str = (char*)calloc(1000,sizeof(char));

    printf("Enter the string:");
    scanf("%s",str);

    valid_paran = isValid(str);

    printf("%s is valid paranthesis %d\n",
            str, valid_paran);

    return 0;
}

bool isValid(char *s)
{
    int str_len = 0;
    char *stack;
    int i = 0;
    char pop_c = NULL;

    str_len = strlen(s);
    stack = (char*)calloc(str_len,sizeof(char));

    if((str_len%2)){
        return FALSE;
    } else {
        for(i=0;i<str_len;i++){
            if(s[i]=='(' || s[i] == '[' || s[i] == '{'){
                push(stack,s[i]);
            }else if(s[i] == ')' || s[i] == ']' || s[i] =='}'){
                pop_c = pop(&stack);

                if(pop_c == '(' && s[i]==')') {
                    printf("popped out successfully\n");
                }else if(pop_c == '[' && s[i] == ']') {
                    printf("popped out successfully\n");
                } else if(pop_c == '{' && s[i] == '}') {
                    printf("popped out successfully\n");
                }else {
                    push(stack,pop_c);
                }
            }
        }

        if(stack_empty(stack)){
            return TRUE;
        }else {
            return FALSE;
        }
    }
}

void push(char *stack,char c)
{
   int str_len = 0;
   str_len = strlen(stack);
    
   stack[str_len++] = c;
   stack[str_len] = '\0';
}

char pop(char **stack)
{
    char pop_c = NULL;
    int str_len = 0;
    
    str_len = strlen(*stack);

    if(*stack){
        pop_c = (*stack)[str_len-1];
        (*stack)[str_len-1] = '\0';
        printf("size is %d\n",str_len-1);
    }
    return pop_c;
}    

bool stack_empty(char *stack)
{
    if(!strlen(stack)) {
        return TRUE;
    }else {
        return FALSE;
    }
}

