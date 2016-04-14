#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* longestCommonPrefix(char **strs, int strsSize);

int main()
{
    int num_str;
    char **str;
    char *op_str = NULL;
    int i;

    printf("Enter the number of strings:");
    scanf("%d",&num_str);

    str = (char**)calloc(num_str, sizeof(char*));

    printf("Enter %d strings\n",num_str);

    for(i=0;i<num_str;i++) {
        str[i] = (char*)calloc(100,sizeof(char));
        scanf("%s",str[i]);
    }
    
    op_str = longestCommonPrefix(str,num_str);

    printf("Longest common Prefix is %s\n",op_str);

    return 0;
}

char* longestCommonPrefix(char **strs, int strsSize)
{
    int i,j,k;
    int long_common_prefix_len = 0;
    int pref_str_len = 0;
    char *ret_str;
    int len_array[strsSize];

    ret_str = (char*)calloc(1000,sizeof(char));

    if(strsSize) {
        
        for(i=0;i<strsSize;i++) {
            len_array[i] = strlen(strs[i]);
       }

        strcpy(ret_str,strs[0]);
        long_common_prefix_len = len_array[0];
        
        for(i=0;i<strsSize;i++) {
                pref_str_len = 0;
            for(j=0;j<strsSize;j++) {
                pref_str_len = 0;
                if(len_array[j] <= len_array[i] && i!=j) {
                    for(k=0;k<len_array[i];k++) {
                        if(strs[i][k]!='\0' && strs[j][k] !='\0' && strs[i][k] == strs[j][k]) {
                            pref_str_len++;
                        }else {
                            break;
                        }
                    }
                    if(pref_str_len < long_common_prefix_len) {
                        long_common_prefix_len = pref_str_len;
                        memset(ret_str,'\0',1000);
                        for(k=0;k<pref_str_len;k++) {
                            ret_str[k] = strs[i][k];
                        }

                    }
                }
            }
        }
    }
    return ret_str;
}  
