#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int lengthOfLongestSubstring(char *str);
int search(char *str, char c);

int main()
{
    char *main_string;
    int len = 0;
    clock_t t;
    
    main_string = (char*)calloc(1000000,sizeof(char));
    printf("Enter the string:");
    scanf("%s",main_string);

    t = clock();
    len = lengthOfLongestSubstring(main_string);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                     
    printf("Our function took %f seconds to execute \n", time_taken);

    printf("Length of longest substring is %d\n", len);

    return 0;
}

int lengthOfLongestSubstring(char *str)
{
    int i,j,k;
    char *old_sub_str;
    char *sub_str;
    int found;
    int len_of_string = 0;

    len_of_string = strlen(str);
    old_sub_str = (char*)calloc(len_of_string,sizeof(char));
    sub_str = (char*)calloc(len_of_string,sizeof(char));

    for(i=0;i<len_of_string;i++) {
        k=0;
        memset(sub_str,'\0',len_of_string);
        for(j=i;j<len_of_string;j++) {
            /*To search in the already formed sub_string 
             * whether this character is already present or not */
            found = search(sub_str,str[j]);
            if(!found) {
                sub_str[k++] = str[j];
            }
            /*If not found, comparing saved sub_string with current
             * sub_string and (if we reached end of string or we have
             * encountered already available char in sub_string) */
            if((strlen(sub_str) > strlen(old_sub_str)) &&
                    ((j == len_of_string -1) || found)) {
                sub_str[k] = '\0';
                memset(old_sub_str,'\0',len_of_string);
                strcpy(old_sub_str,sub_str);
                break;
            }
        }
        
    }
    printf("Longest substring is %s\n", old_sub_str);
    return strlen(old_sub_str);
}

int search(char *str, char c)
{
    int i;

    for(i=0;i<strlen(str);i++) {
        if(str[i] == c) {
            return 1;
        }
    }
    return 0;
}
