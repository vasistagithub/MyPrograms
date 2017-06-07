#include <stdio.h>
#include <stdlib.h>

int get_endian();

int main()
{
    int endianness = 0; /*Default is big-endian assumed*/
    int num = 0;

    endianness = get_endian();
    if(endianness) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
    printf("Enter number to be reversed byte order way:");
    scanf("%d", &num);
    printf("%d after byte reversal is %d\n", num, reverse_byte_by_byte(num));
    return 0;
}

int get_endian()
{
    unsigned int num = 01;
    char *ptr = NULL;
    
    ptr = (char*)&num;
    printf("value in ptr is %d\n", (*ptr));

    return (*ptr);
}

int reverse_byte_by_byte(int num)
{
    unsigned int c1, c2, c3, c4;
    int final = 0;

    c1 = num & 255;
    c2 = (num >> 8) & 255;
    c3 = (num >> 16) & 255;
    c4 = (num >> 24) & 255;

    final = (c1 << 24) | (c2 << 16) | (c3 << 8) | c4;

    return final;
}
