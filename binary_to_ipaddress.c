#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int bin_ipaddr = 0;
    unsigned char byte[4] = "\0";

    printf("Enter the IP address in binary format:");
    scanf("%d",&bin_ipaddr);

    byte[0] = bin_ipaddr & 0xFF;
    byte[1] = (bin_ipaddr >> 8) & 0xFF;
    byte[2] = (bin_ipaddr >> 16) & 0xFF;
    byte[3] = (bin_ipaddr >> 24) & 0xFF;

    printf("%d.%d.%d.%d\n", byte[3],byte[2], byte[1], byte[0]);

    return 0;
}

