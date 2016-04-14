#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *str;
    int first_loc = 0;
    char *needle;

    str = (char*)calloc(1000,sizeof(char));
    needle = (char*)calloc(1000,sizeof(char));

    printf("Enter the string:");
    gets(str);

    printf("Enter the needle:");
    gets(needle);

    first_loc = strStr(str,needle);

    printf("First occurance of %s is %d\n",
            needle,first_loc);

    return 0;
}

int strStr(char *haystack, char* needle)
{
    int i,j;

    for(i=0;i<strlen(haystack);i++) {
        if(haystack[i] = needle[0]) {
            for(j=0;j<strlen(needle);j++) {
                if(haystack[i+j] == needle[j]) {
                    continue;
                } else {
                    break;
                }
            }
            if(j == strlen(needle)) {
                return i;
            }
        }
    }
    return -1;
}
