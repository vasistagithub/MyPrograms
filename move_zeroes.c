#include<stdio.h>
#include<stdlib.h>

void moveZeroes(int *nums, int numsSize);
void swap(int *a,int *b);

int main()
{
    int len_array;
    int i;
    int *num = NULL;

    printf("Enter the array length:");
    scanf("%d",&len_array);

    num = (int*)calloc(len_array,sizeof(int));

    for(i=0;i<len_array;i++) {
        printf("Enter the element:");
        scanf("%d",&num[i]);
    }
    moveZeroes(num,len_array);

    return 0;
}

void moveZeroes(int *nums, int numsSize)
{
    int i;
    int j;

    for(i=0;i<numsSize;i++) {
        if(nums[i] == 0) {
            for(j=i+1;j<numsSize;j++){
                if(nums[j] != 0) {
                    printf("Swapping %d->%d and %d->%d\n",
                            i,nums[i],j,nums[j]);
                    swap(&nums[i], &nums[j]);
                    break;
                }
            }
        }
    }
    printf("Array after zeroes movement is\n");
    for(i=0;i<numsSize;i++) {
        printf("%d\t",nums[i]);
    }
}

void swap(int *a,int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
