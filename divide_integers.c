#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int dividend,divisor;
    int quotient = 0;

    printf("Enter the dividend:");
    scanf("%d",&dividend);

    printf("Enter the divisor:");
    scanf("%d",&divisor);

    quotient = divide(dividend,divisor);

    printf("Division result of %d and %d is %d\n",
            dividend,divisor,quotient);

    return 0;
}

int divide(int dividend,int divisor)
{
    int quotient = 0;
    int neg = 0;
    int bit_shift = 0;

    if(divisor) {
        if(divisor <= INT_MIN || divisor >=INT_MAX) {
            return 0;
        }
        if(dividend < 0 && divisor < 0) {
            if(dividend > divisor) {
                return 0;
            }

            dividend*=-1;
            divisor*=-1;
        } else if((dividend < 0 || divisor < 0)) {
            
            neg = 1;
            if(dividend < 0) {
                dividend *= -1;
            }
            if(divisor < 0) {
                divisor *= -1;
            }
        }

        if(dividend < divisor) {
            return 0;
        } else {
            bit_shift = (divisor & (divisor-1));
            if(divisor == 1) {
                quotient = dividend;
            } else if (!(bit_shift)){
                divisor >>=1;
                while(divisor) {
                    dividend >>= 1;
                    quotient = dividend;
                    printf("dividend is %d\n",dividend);
                    divisor >>= 1;
                }
            } else {
               while(dividend >= divisor) {
                   quotient++;
                   dividend -= divisor;
               }
            }
        }
       // printf("quotient is %d\n", quotient);

        if(neg) {
            quotient *= -1;
        }
        return quotient;
    } else {
        return INT_MAX;
    }
}  
