#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char*, char*);
void swap(char*,char*);

int main()
{
    char *str1 = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str1 = (char*)calloc(1000,sizeof(char));

    str2 = (char*)calloc(1000,sizeof(char));
    
    printf("Enter binary string1:");
    scanf("%s",str1);

    printf("Enter binary string2:");
    scanf("%s",str2);

    str3 = addBinary(str1,str2);

    printf("sum is %s\n",str3);

    return 0;
}

char* addBinary(char *a, char *b)
{
    int i,j;
    int carry = 0;
    char *c;
    int max_len = 0;
    int k = 0;
    int sum = 0;

    i = strlen(a);
    j = strlen(b);
    
    if(i>=j) {
        max_len = i;
    } else {
        max_len = j;
    }
    
    i--;
    j--;

    c = (char*)calloc(max_len+1,sizeof(char));
    
    carry = 0;
    sum = 0;

    while(i >=0 && j >=0) {
        sum = a[i]-'0' + b[j]-'0' + carry;
        carry = sum/2;
        c[k++] = sum%2 + '0';
        i--;
        j--;
    }

    if(i<0) {
        while(j>=0) {
            sum = b[j]-'0' + carry;
            carry = sum/2;
            c[k++] = sum%2 + '0';
            j--;
        }
    }

    if(j<0) {
        while(i>=0) {
            sum = a[i] -'0' + carry;
            carry = sum/2;
            c[k++] = sum%2 + '0';
            i--;
        }
    }

    if(carry) {
        c[k++] = carry + '0';
    }
    c[k] = '\0';

    for(i=0;i<k/2;i++) {
        swap(&c[i],&c[k-1-i]);
    }

    return c;
}

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b =  temp;
}
