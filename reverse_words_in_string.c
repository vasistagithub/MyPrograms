#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_str(char*, int);
void swap(char*, char*);

int main()
{
    char str[100];
    int len_str = 0;
    int i,j;
    int new_pos = 0;

    printf("Enter the string:");
    gets(str);
    len_str = strlen(str);

    reverse_str(str, len_str);

    printf("Reversing a complete string is %s\n", str);
    
    i = 0;
    while (i < len_str) {
        j = i;
        while(str[i] != ' ' && str[i] != '\0') {
            i++;
        }
        i--;
        new_pos = i;
        while(j < i) {
            swap(&str[j], &str[i]);
            j++;
            i--;
        }
        i = new_pos+2;
    }
    printf("Reverse words in given string is %s\n", str);
    
    return 0;
}

void reverse_str(char *str, int len_str)
{
    int i = 0;
    int j = len_str-1;

    while(i < j) {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
}

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b =temp;
}
