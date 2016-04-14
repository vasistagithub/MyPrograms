#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size_array = 0;
    int *num;
    int input;
    int count = 0;
    int i = 0;

    num = (int*)calloc(size_array,sizeof(int));

    printf("Enter the size of array:");
    scanf("%d",&size_array);

    printf("Enter the elements into array\n");
    for(i=0;i<size_array;i++) {
        scanf("%d",&num[i]);
    }

    printf("Enter the number to be searched:");
    scanf("%d",&input);

    count = removeElement(num,size_array,input);

    printf("Number of remaining elements are:%d\n",count);

    return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    int i;
    int count = 0;

    for(i=0;i<numsSize;i++) {
        if(nums[i] == val) {
            count++;
        }
    }
    return (numsSize-count);
}
