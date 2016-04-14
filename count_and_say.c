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
    int mod1 = 0;
    int mod = 0;
    int last_digit = 0;

    if(num/10){
        while(num) {
            printf("count is %d\n",count);
            mod1 = num%10;

            if(num/10) {
                //count ++;
                num/=10;
                mod = num%10;
                num*=10;
            } 
            if(mod1 == mod) {
                count++;
                printf("%d -> %d\n",mod1,count);
            } else {
                printf("%d -> %d\n",mod1,count);
                mod1 = mod;
                if(num/100) {
                    count = 1;
            }
                num/=10;
        }
    } else {
        if(num) {
            printf("%d -> %d\n",num,1);
        }
    }
}
