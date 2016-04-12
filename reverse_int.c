#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int reverse(int);
int power(int,int);

int main()
{
    int num;
    int rev_num;

    printf("Enter the number:");
    scanf("%d",&num);

    rev_num = reverse(num);

    printf("Reverse of %d is %d\n",num, rev_num);

    return 0;
}

int reverse(int num)
{
    int neg = 0;
    int temp_num = num;
    int rev_num = 0;
    int i = 0;
    int mod_val = 0;
    int digit_count = 0;

    if(num <= INT_MIN || num >= INT_MAX){
        return 0;
    }
    if(num < 0) {
        neg = 1;
    }
    
    if(neg) {
        temp_num*= -1;
    }
    /*Finding number of digits in the integer 
     * passed*/
    while(temp_num) {
        digit_count++;
        temp_num/=10;
    }
    digit_count--;
    temp_num = (neg?num*-1:num);
    /*Reversing the number by taking each digit
     * and multiplying with the power of 10 of corresponding
     * digit number*/
    while(temp_num) {
        mod_val = temp_num%10;
        printf("mod_val is %d\n", mod_val);
        printf("digit_count is %d\n",digit_count);
        printf("MIN and MAX are %d and %d\n",INT_MIN, INT_MAX);
        if(digit_count > 10) {
            return 0;
        }
        rev_num += mod_val*(power(10,digit_count));
        if(rev_num > INT_MAX) {
            return 0;
        }
        printf("rev_num is %d\n",rev_num);
        digit_count--;
        temp_num/=10;
    }

    if(neg) {
        return rev_num*-1;
    } else {
        return rev_num;
    }
}

int power(int x,int y)
{
    long int ret_val = 1;
    while(y) {
        ret_val*=x;
        y--;
    }
    return ret_val;
}
