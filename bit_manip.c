#include <stdio.h>
#include <stdlib.h>

int get_endian();

int main()
{
    int endianness = 0; /*Default is big-endian assumed*/
    
    endianness = get_endian();
    if(endianness) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

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
