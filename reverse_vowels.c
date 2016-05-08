#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverseVowels(char *str);
char* reverseVowels2(char *str);
void swap(char*,char*);

int main()
{
    char str[100];

    printf("Enter the string:");
    scanf("%s",str);

    printf("Reversed vowel string is %s\n",
            reverseVowels(str));

    printf("Now the string is %s\n",str);

    printf("Reversed vowel string with other algo is %s\n",
            reverseVowels2(str));

    return 0;
}

char* reverseVowels(char *str)
{
    int len_str = strlen(str);
    int i,j;

    for(i=0;i<len_str;i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u') {
            for(j = i +1; j<len_str;j++) {
              if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' ||
                str[j] == 'o' || str[j] == 'u') {
                  printf("Swapping %d-%c and %d-%c\n",
                          i,str[i],j,str[j]);
                  swap(&str[i],&str[j]);
              }
            }
        }
    }

    return str;
}
void swap(char*a, char*b)
{
    char temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

char* reverseVowels2(char *str)
{
    int len_str = strlen(str);
    int i = 0;
    int j = 0;
    int k = 0;

    int *vowel_loc;

    vowel_loc = (int*)calloc(len_str,sizeof(int));

    for(i=0,j=0;i<len_str;i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
                str[i] == 'U') {
            vowel_loc[j++] = i;
        }
    }

    for(i=0;i<j-1;i++) {
        for(k=i+1;k<j;k++ ) {
            swap(&str[vowel_loc[i]],&str[vowel_loc[k]]);
        }
    }
    return str;
}
        
