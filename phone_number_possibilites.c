#include <stdio.h>
#include <stdlib.h>

char t9[10][3] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz$", "@#*"};

void print_string(char *number, int length, int index, char* path);

int main()
{
    int i = 0;
    char path[10] = {'\0'};
    char number[10] = {'\0'};
    int length = 0;
    int col = 0;

    printf("Enter the phone number length:");
    scanf("%d", &length);
    
    printf("Enter the phone number of %d digits:", length);
    for(i = 0; i <= length; i++) {
        scanf("%c", &number[i]);
    }
    
    printf("Given phone number is %s\n", number);
    printf("printing T9 keyboard\n");
    for(i = 0;i < 10; i++) {
        for(col = 0; col < 3; col++) {
            printf("%c--", t9[i][col]);
        }
        printf("\n");
    }
    printf("Printing all possible strings of %s phone number\n", number); 
    print_string(number, length+1, 1, path);

    return 0;
}

void print_string(char *number, int length, int index, char* path)
{
    int col = 0;
    int i;
    int row;

    if(index == length) {
        for(i = 0; i< length; i++) {
            printf("%c", (path)[i]);
        }
        printf("\n");
    } else {
        for(col = 0; col <3; col++) {
            row = number[index] - '0';
             (path)[index] = t9[row][col];
            print_string(number, length, index + 1, path);
        }
    }
}
