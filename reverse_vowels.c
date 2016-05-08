#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverseVowels(char *str);
char* reverseVowels2(char *str);
char* reverseVowels3(char *str);
char* reverseVowels4(char *str);
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
    
    printf("Now the string is %s\n",str);

    printf("Reversed vowel string with other algo is %s\n",
            reverseVowels3(str));


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
char* reverseVowels3(char *str)
{
    int len_str = strlen(str);
    int i = 0;
    int j = 0;

    for(i=0,j=len_str-1;i<len_str/2;i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
                str[i] == 'U') {
            while(j >= len_str/2) {
                if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' ||
                    str[j] == 'o' || str[j] == 'u' || str[j] == 'A' ||
                    str[j] == 'E' || str[j] == 'I' || str[j] == 'O' ||
                    str[j] == 'U') {
                    printf("Swapping %d-%c and %d-%c\n",
                            i,str[i],j,str[j]);    
                    swap(&str[i],&str[j]);
                    j--;
                    break;
                } 
               j--; 
            }
        }
    }
    return str;
}
char* reverseVowels4(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len_str = 0;
    int index = 0;

    while(str) {
        index = i;
        while(str[i] != ' ' || str[i] != '\n') { 
            i++;
        }
        len_str = (i - index) + 1;
            for(k=index,j=i-1;k<(index+len_str/2);k++) {
            if(str[k] == 'a' || str[k] == 'e' || str[k] == 'i' ||
                    str[k] == 'o' || str[k] == 'u' || str[k] == 'A' ||
                    str[k] == 'E' || str[k] == 'I' || str[k] == 'O' ||
                    str[k] == 'U') {
                while(j >= (index + len_str/2)) {
                    if(str[j] == 'a' || str[j] == 'e' || str[j] == 'i' ||
                        str[j] == 'o' || str[j] == 'u' || str[j] == 'A' ||
                        str[j] == 'E' || str[j] == 'I' || str[j] == 'O' ||
                        str[j] == 'U') {
                        printf("Swapping %d-%c and %d-%c\n",
                                i,str[i],j,str[j]);    
                        swap(&str[i],&str[j]);
                        j--;
                        break;
                    } 
                   j--; 
                }
            }
        }
    }
    return str;
}
