#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char*,char*);
char* strRev(char*);
void swap(char *a, char *b);

int main()
{
    char *s1, *s2;
    char *s3 = NULL;

    s1 = (char*)calloc(100,sizeof(char));
    s2 = (char*)calloc(100,sizeof(char));

    printf("Enter the first binary num:");
    scanf("%s",s1);
    printf("Enter the second binary num:");
    scanf("%s",s2);

    s3 = addBinary(s1,s2);

    printf("Added binary string of %s and %s is %s\n",
            s1,s2,s3);

    return 0;
}

char* addBinary(char *a, char *b)
{
    int len1,len2;
    char carry = '0';
    int i =0;
    int j = 0;
    char *ret_str = NULL;
    int max_len = 0;

    len1 = strlen(a);
    len2 = strlen(b);

    printf("len1 is %d and len2 is %d\n",
            len1,len2);

    if(len1 >= len2) {
        max_len = len1;
    } else {
        max_len = len2;
    }
    ret_str = (char*)calloc(max_len+1,sizeof(char));

    len1--;
    len2--;

    while(len1 >= 0  && len2 >= 0) {
        if(a[len1]=='1' && b[len2] == '1') {
            if(carry == '1') {
                ret_str[i++] = '1';
            } else {
                ret_str[i++] = '0';
                carry = '1';
            }
        } else if(a[len1] == '0' && b[len2] == '0') {
            if(carry == '1') {
                ret_str[i++] = '1';
            } else {
                ret_str[i++] = '0';
            }
            carry = '0';
        } else {
            if(carry == '1') {
                ret_str[i++] = '0';
            } else {
                ret_str[i++] = '1';
                carry = '0';
            }
        }
        len1--;
        len2--;
        
        printf("i is %d\n",i);
        printf("%c-->",ret_str[i-1]);
    }

    if(len1 < 0) {
        
        while(len2 >=0) {
            if(carry == '1') {
                if(b[len2] == '0') {
                    ret_str[i++] = '1';
                    carry = '0';
                } else {
                    ret_str[i++] = '1';
                    carry = '1';
                }
            } else {
                if(b[len2] == '1') {
                    ret_str[i++] = '1';
                } else {
                    ret_str[i++] = '0';
                }
            }
            printf("%c-->", ret_str[i-1]);
            len2--;
        }
        printf("i is %d\n",i);
        if(carry == '1') {
            ret_str[i] = carry;
        }
    }


    if(len2 < 0) {
        
        while(len1 >=0) {
            if(carry == '1') {
                if(b[len1] == '0') {
                    ret_str[i++] = '1';
                    carry = '0';
                } else {
                    ret_str[i++] = '0';
                    carry = '1';
                }
            } else {
                if(b[len1] == '1') {
                    ret_str[i++] = '1';
                } else {
                    ret_str[i++] = '0';
                }
            }
            printf("%c-->",ret_str[i-1]);
            len1--;
        }
        printf("i is %d\n",i);
        printf("carry is %c\n",carry);

        if(carry == '1') {
            ret_str[i] = carry;
        }
    }

    printf("output string is %s\n",ret_str);
   
    return strRev(ret_str);
}


char* strRev(char *s)
{
    int i;
    int str_len = strlen(s);

    printf("string length is %d\n",str_len);
    for(i=0;i<str_len/2;i++) {
        swap(&s[i],&s[str_len-1-i]);
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
