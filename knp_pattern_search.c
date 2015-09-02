#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter the String:");
    scanf("%s",string);

    printf("Enter the pattern:");
    scanf("%s", pattern);

    pattern_loc = knp_search(string,pattern);

    if(pattern_loc != -1) {
        printf("%s is found in %s at %d location\n",
                pattern, string, pattern_loc);
    } else {
        printf("%s not found in %s\n", pattern, string);
    }

    return 0;
}


int knp_search(char *string, char *pattern)
{
    int pattern_p;
    int string_p;

    pattern_p = 0;
    string_p = 0;

    while(pattern_p <= strlen(pattern) || string_p < strlen(string)) {
        if(pattern[pattern_p] == string[string_p]) {
            pattern_p++;
            string_p++;
        } else {
            if(pattern_p) {
                string_p++;
            } else {
                pattern_p = shift_pattern[pattern_p] + 1;
            }
        }
    }

    if(pattern_p <= strlen(pattern)) {
        return -1;
    } else {
        return 0;
    }
}


