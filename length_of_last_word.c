#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[1000];
    int len_last = 0;

    printf("Enter the string:");
    gets(str);

    printf("Input string is %s\n",str);

    printf("len of str is %d\n",
            strlen(str));

    len_last = lengthOfLastWord(str);
    
    printf("Length of last word is %d\n",
            len_last);

    return 0;
}

int lengthOfLastWord(char *s)
{
    int i = 0;
    int str_len;
    int count = 0;

    str_len = strlen(s);
    str_len --;
    while(s[str_len] == ' ' || s[str_len]=='\n'){
        str_len--;
    }
    for(i=str_len;i>=0;i--) {
        if(s[i]==' ' || s[i]=='\n') {
            break;
        } else {
            count++;
        }
    }
    return count;
}
        


