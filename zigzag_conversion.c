#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define TRUE 1
#define FALSE 0

char* convert(char*,int);
void append_char(char**,char);

int main()
{
    char str[1000];
    char *upd_str;
    int rows;

    printf("Enter the string:");
    scanf("%s",str);
    printf("Enter the number of rows:");
    scanf("%d",&rows);

    upd_str = convert(str,rows);
    printf("Converted string is %s\n", upd_str);

    return 0;
}

char* convert(char* str, int rows)
{
    int len_of_str = strlen(str);
    char *ret_str;
    int i,j,inc;
    int ref_val = 0;
    bool even = FALSE;

    ret_str = (char*)calloc(len_of_str,sizeof(char));
    ref_val = rows/2;

    if(len_of_str <= rows) {
        printf("updated string is %s\n",str);
        return str;
    } else {
        if(!(rows%2)) {
            ref_val--;
        } 
        for(i=0;i<rows;i++) {
            append_char(&ret_str,str[i]);
            if(ref_val) {    
                inc = rows + 1;
                j = i + inc;
                while(j< len_of_str) {
                    append_char(&ret_str, str[j]);
                    j+=inc;
                }
                ref_val--;
            } else {
               j = i;
               if(rows%2) {
                inc = rows/2 + 1;
                j += inc; 
               } else {
                    inc = rows/2;
                    even = TRUE;
                    j+=inc + 1; 
               }
               while(j<len_of_str) {
                    append_char(&ret_str,str[j]);
                    if(even) {
                        even = FALSE;
                        j+=inc;
                    } else {
                        even = TRUE;
                        j+=inc +1;
                    }
                }
                ref_val = rows/2;
            }
        }
        printf("updated string is %s\n",ret_str);
        return ret_str;
    }
}

void append_char(char** str, char c)
{
    int len = strlen(*str);
    (*str)[len] = c;
}
