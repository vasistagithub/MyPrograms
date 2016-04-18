#include<stdio.h>
#include<stdlib.h>


int powerOfThree(int);

int main()
{
    int ret_op = 0;
    int num = 0;

    printf("Enter the number:");
    scanf("%d",&num);

    ret_op = powerOfThree(num);

    printf("%d is powerofthree %d\n",
            num,ret_op);

    return 0;
}

int powerOfThree(int num)
{

    if(num <0 || num%3) {
       return 0;
    } else {
        if(num == 0) {
            return 1;
        } else {
            while(num) {
                if(num%3) {
                    return 0;
                }
                num/=3;
                if(num == 1) {
                    return 1;
                }
                //printf("num is %d\n",num);
            }

        }
    } 
    return 0;
}
