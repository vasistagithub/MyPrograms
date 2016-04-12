#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int*,int);

int main()
{
    int i;
    int size_array = 0;
    int *num_array;
    int uniq_elem_count = 0;

    printf("Enter the size of array:");
    scanf("%d",&size_array);

    num_array = (int*)calloc(size_array,sizeof(int));

    for(i=0;i<size_array;i++) {
        printf("Enter the num:");
        scanf("%d",&num_array[i]);
    }

    uniq_elem_count = removeDuplicates(num_array,size_array);
    
    printf("Number of unique elements in the array is %d\n",
            uniq_elem_count);

    return 0;
}

int removeDuplicates(int *nums, int numsSize)
{
    int i,j;
    int count = 0;
    int new_num;

    for(i=0;i<numsSize;i++){
        new_num = nums[i];
        printf("new_num is %d\n",
                new_num);
        count++;
        for(j=i+1;j<numsSize;j++){
            if(nums[j] != new_num) {
                break;
            }
        }
        if(j < numsSize) {
            nums[count] = nums[j];
        }
        i = j-1;
    }
    for(i=0;i<count;i++) {
        printf("%d\t",nums[i]);
    }
    nums[i] = '\0';
    return count;
}


