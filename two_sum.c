#include<stdio.h>
#include<stdlib.h>

int *twoSum(int*, int, int);

int main()
{
    int     i;
    int     numsSize;
    int*    nums;
    int     target;
    int*    output;

    printf("Enter the size of array:");
    scanf("%d",&numsSize);
    printf("Enter %d elements:\n", numsSize);

    for(i=0;i<numsSize;i++) {
        scanf("%d",&nums[i]);
    }
    printf("Enter the target:");
    scanf("%d",&target);

    output = twoSum(nums,numsSize,target);

    printf("%d and %d sums to %d\n",
            output[0], output[1], target);

    return 0;
}

int* twoSum(int* nums, int numsSize, int target) {

    int i,j;
    int *output;

    output = (int*)calloc(2, sizeof(int));

    for(i=0;i<numsSize;i++) {
        output[0] = i;
        for(j=0;j<numsSize;j++) {
            if(i == j) {
                continue;
            } else {
                if(nums[j] == (target - nums[output[0]])) {
                    output[1] = j;
                    return output;
                }
            }
        }
    }
}
