#include<stdio.h>
#include<stdlib.h>

char* countAndSay(int num);
void swap(char*,char*);

int main()
{
    int num;
    char* say_op;

    printf("Enter the number:");
    scanf("%d",&num);

    say_op = countAndSay(num);

    printf("%d count and say is %s\n",
            num,say_op);

    return 0;
}

char* countAndSay(int num)
{
    int tmp_num = num;
    int count = 0;
    int val ;
    int val1;
    int int_count = 0;
    int new_tmp_num = 0;
    char *a = NULL;
    int k = 0;
    int i=0;
    int j = 0;

    a = (char*)calloc(100,sizeof(char));

    while(tmp_num) {
        count++;
        tmp_num/=10;
    }

    tmp_num = num;

    for(i=count-1;i>=0;i--) {
        val = tmp_num%10;
        new_tmp_num = tmp_num/10;
        int_count = 1;

        for(j=i-1;j>=0;j--) {
            val1 = new_tmp_num%10;
            if(val == val1) {
                int_count++;
            } else {
                break;
            }
            new_tmp_num/=10;
        }
        i = j+1;
        a[k++] = val+ '0';
        a[k++] = int_count + '0';
        tmp_num = new_tmp_num;
    }
            
    a[k] = '\0';
    for(i=0;i<k/2;i++) {
        swap(&a[i],&a[k-1-i]);
    }
    printf("Length of num is %d\n",count);

    return a;
}
void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
