#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* plusOne(int *digits, int digitsSize, int* returnSize);
void swap(int *a, int *b);
    
int main()
{
    int num_digits = 0;
    int i;
    int *num;
    int returnSize = 0;
    int *plusOneNum = NULL;

    printf("Enter the number of digits in an array:");
    scanf("%d",&num_digits);

    num = (int*)calloc(num_digits,sizeof(int));
    
    printf("Enter the digits slowly\n");
    for(i=0;i<num_digits;i++) {
        scanf("%d",&num[i]);
    }

    plusOneNum = plusOne(num,num_digits,&returnSize);

    printf("Plus One number is:");
    for(i=0;i<returnSize;i++) {
        printf("%d",plusOneNum[i]);
    }
    printf("\n");

    return 0;
}

int* plusOne(int *digits, int digitsSize, int* returnSize)
{
    int carry = 0;
    int i,j;

    int* ret_digits = NULL;
    ret_digits = (int*)calloc(digitsSize + 1, sizeof(int));

    ret_digits[0] = digits[digitsSize-1] + 1;
    if(ret_digits[0]/10) {
        carry = ret_digits[0]/10;
        ret_digits[0]%=10;
    }
    j=1;
    i = digitsSize-2;
    while(i>=0) {
        ret_digits[j] = carry + digits[i];
        carry = ret_digits[j]/10;
        ret_digits[j]%=10;
        j++;
        i--;
    }
    while(carry) {
        ret_digits[j++] = carry%10;
        carry/=10;
    }
    ret_digits[j] = '\0';
    *returnSize = j;
  
    printf("Return size is %d\n",*returnSize);

    for(i=0;i<j/2;i++) {
       swap(&ret_digits[i],&ret_digits[j-1-i]);
    } 
    return ret_digits;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
