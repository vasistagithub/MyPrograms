#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define bool int
#define TRUE 1
#define FALSE 0

int power(int,int);

int main()
{
    int num;
    bool palindrome = FALSE;

    printf("Enter the number:");
    scanf("%d",&num);

    palindrome = isPalindrome(num);

    printf("%d is a palindrome %d\n",
            num,palindrome);

    return 0;
}

bool isPalindrome(int num)
{
    int val = 0;
    int i = 0;
    int mod_val = 0;
    bool neg = 0;
    int orig_num = num;

    if(num > INT_MAX || num < INT_MIN || num < 0) {
        return FALSE;
    }

    while(num) {
        num/=10;
        i++;
    }
    num = orig_num;
    i--;
    while(num) {
        mod_val = num%10;
        val += mod_val * power(10,i);
        i--;
        num/=10;
        printf("val is %d\n",val);
    }

    if(val == orig_num) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int power(int x,int y)
{
    int ret_val = 1;
    while(y) {
        ret_val*=x;
        y--;
    }
    return ret_val;
}
