#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permute_string (char *str, int l, int r);
void swap(char*, char*);

int main()
{
    char s[100] = "\0";

    printf("Enter the string:");
    scanf("%s", s);

    permute_string(s, 0 , strlen(s)-1);

    return 0;
}

void permute_string (char *str, int l, int r)
{
    int i;

    if (l == r) {
        printf("%s\n", str);
    } else {
        for(i = l; i<=r;i++) {
            swap((str+l), (str+i));
            permute_string(str, l+1, r);
            swap((str+l), (str+i)); // for backtracing to previous level
        }
    }
}

void swap(char *a, char *b)
{
    char temp;
 
    temp = *a;
    *a = *b;
    *b = temp;
}
