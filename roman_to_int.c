#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int romancToNum(char c);

int main()
{
    int num = -1;
    char str[100];

    printf("Enter the roman string:");
    scanf("%s",str);

    num = romanToInt(str);

    printf("The number is %d\n",num);

    return 0;
}

int romanToInt(char *s)
{
    int i = 0;
    char roman_c;
    int num =0;
    int num2 = 0;
    int sum = 0;
    int minus = 0;

    if(s) {

        i = strlen(s) - 1;

        while(i>=0) {
            roman_c = s[i];
            num = romancToNum(roman_c);
            
            if(!minus) {
                sum += num;
            } else {
                sum-= num;
            }
            if(i-1 >=0)  {
                roman_c = s[i-1];
                num2 = romancToNum(roman_c);
                
                if(num2 < num && !minus) {
                    minus = 1;
                } else {
                    minus = 0;
                }
            }
            i--;
        }
    }
    return sum;
}

int romancToNum(char c)
{
    if(c == 'I') {
        return 1;
    } else if(c == 'V') {
        return 5;
    } else if(c == 'L') {
        return 50;
    } else if(c == 'C') {
        return 100;
    } else if(c == 'D') {
        return 500;
    } else if(c == 'M') {
        return 1000;
    } else if(c == 'X'){
        return 10;
    } else {
        return -1;
    }
}
