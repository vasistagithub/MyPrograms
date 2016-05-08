#include<stdio.h>
#include<string.h>

char *reverseString(char *s);
void swap(char*,char*);

int main()
{
    char str[100];

    printf("Enter the string:");
    scanf("%s",str);

    printf("Reversed vowel string is %s\n",
            reverseString(str));

    return 0;
}

char *reverseString(char *s)
{
    int len_str = strlen(s);
    int i = 0;

    for(i=0;i<len_str/2;i++) {
        swap(&s[i],&s[len_str-i-1]);
    }
    return s;
}

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


