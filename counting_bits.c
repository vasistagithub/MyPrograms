#include<stdio.h>
#include<stdlib.h>

int* bits_count(int, int*);
int calc_bits(int);

int main()
{
    int num;
    int* bits_array;
    int i;
    int size_array;

    printf("Enter the number:");
    scanf("%d",&num);
    size_array = num + 1;
    bits_array = bits_count(num, &size_array);

    printf("Output:");
    for(i=0;i<=num;i++) {
        printf("%d\t",bits_array[i]);
    }
    
    free(bits_array);

    return 0;
}

int* bits_count(int num, int* returnSize)
{
    int i;
    int *bits_array;

    bits_array = (int*)calloc((num+1), sizeof(int));
    
    for(i=0;i<=num;i++) {
        bits_array[i] = calc_bits(i);
    }
    return bits_array;
}


int calc_bits(int num)
{
    if(!num) {
        return 0;
    } else {
        if(num%2) {
            return 1 + calc_bits(num/2);
        } else {
            return calc_bits(num/2);
        }
    }
}

