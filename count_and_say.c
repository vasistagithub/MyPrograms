#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    int say_op;

    printf("Enter the number:");
    scanf("%d",&num);

    say_op = countAndSay(num);

    printf("%d count and say is %d\n",
            num,say_op);

    return 0;
}

int countAndSay(int num)
{
    int count = 0;

    mod1 = num%10;

    while(num) {
        mod = num%10;
        num/=10;
