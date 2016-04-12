#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int myAtoi(char*);
long int power(int,int);

int main()
{
    int num;
    char str[100];

    printf("Enter the string:");
    scanf("%s",str);

    num = myAtoi(str);

    printf("string is %s and the number is %d\n",
            str, num);

    return 0;
}

int myAtoi(char *str)
{
    int neg = 0;
    char first_c;
    int tmp_len = 0;
    int str_len = 0;
    int i = 0;
    long int val = 0;
    int pos = 0;
    int enter_str = 0;
    int digit_count = 0;

    if(str) {
        /*Performing all pre-checks to the input string apssed
         * and updated the string to proceed further with 
         * next level of string to digit conversion 
         */        
        for(i=0;i<strlen(str);i++){
            if(str[i] == ' ' && !enter_str){
                continue;
            } else {
                enter_str = 1;
                if(!(str[i] >='0' && str[i]<='9' || str[i]=='+'||str[i]=='-')){
                    str[i]='\0';
                } else {
                    if(str[i] >='0' && str[i]<='9'){
                        digit_count++;
                    }
                }
            }
        }

        str_len = strlen(str);
       
        /*Identifying the + and - symbols 
         * for return value
         */ 
        for(i=0;i<str_len;i++){
            if(str[i] == '+'){
                pos++;
            } else if(str[i] == '-'){
                neg++;
            }
        }
        /*Returning the max & min values
         * if passed string value is more than
         * max and min limits
         */
        if(digit_count > 10 && !neg) {
            return INT_MAX;
        } else if(digit_count >10 && neg) {
            return INT_MIN;
        }
        if(pos + neg > 1){
            return 0;
        }
        
        if(neg || pos) {
            str_len--;
        }
        tmp_len = str_len;
        tmp_len--;
        /*Converting the digits passed in the string format to
         * integer format
         */
        if(neg || pos){
            for(i=1;i<=str_len;i++){
                if(str[i]>='0' && str[i]<='9'){
                    val += (str[i] - '0') * power(10,tmp_len);
                } else if(val) {
                    val/=power(10,(str_len-i)+1);
                    break;
                }
               tmp_len--; 
            }
        } else {
            for(i=0;i<str_len;i++){
                if(str[i]>='0' && str[i]<='9'){
                    val += (str[i] - '0') * power(10,tmp_len);
                } else if(val) {
                    val/=power(10,(str_len-i));
                    break;
                }
                tmp_len--;
            }
        }
        if(val >= INT_MAX && !neg) {
            return INT_MAX;
        }else if(val >= INT_MAX && neg) {
            return INT_MIN;
        }
        if(neg) {
            return val*-1;
        } else {
            return val;
        }
    } else {
        return val;
    }
}


long int power(int x,int y)
{
    long int ret_val = 1;
    while(y) {
        ret_val*=x;
        y--;
    }
    return ret_val;
}
