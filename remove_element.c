#include<stdio.h>
#include<stdlib.h>

int swap(int*,int*);

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
    int i,j;
    int count = 0;
    int update = 0;

    for(i=0;i<numsSize;i++) {
        if(nums[i] == val) {
            count++;
        }
    }

    i = 0;
    j = numsSize - 1;

    while(i<=j) {
        /*Traverse from left, take the left element
         * and if its equal to "val", then swap this element
         * with non-val from right */
        while(nums[i] == val) {
            if(nums[j] != val) {
                printf("swap values are %d(index)->%d and %d(index)->%d\n",
                        i,nums[i],j,nums[j]);
                swap(&nums[i],&nums[j]);
                if(i > j) {
                    update = 1;
                }
            }
            j--;
        }
        i++;
    }

    /*TO be safe, if some spill up of last extra swapping happened,
     * re-swap back*/
    if(update) {
        i--;
        j++;
        swap(&nums[i],&nums[j]);
    }
    printf("updated array is\n");
    for(i=0;i<numsSize;i++) {
        printf("%d\t",nums[i]);
    }
    return (numsSize-count);
}

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
