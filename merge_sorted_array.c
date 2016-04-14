#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int m, int *nums2, int n);

int main()
{
    int *nums1, *nums2;
    int numsSize1, numsSize2;
    int i;

    printf("Enter array size1:");
    scanf("%d",&numsSize1);

    printf("Enter array size2:");
    scanf("%d",&numsSize2);

    nums1 = (int*)calloc(numsSize1 + numsSize2 + 1,sizeof(int));

    nums2 = (int*)calloc(numsSize2,sizeof(int));

    printf("Enter sorted elements for array1\n");
    for(i=0;i<numsSize1;i++) {
        scanf("%d",&nums1[i]);
    }

    printf("Enter sorted elements for array2\n");
    for(i=0;i<numsSize2;i++) {
        scanf("%d",&nums2[i]);
    }


    merge(nums1,numsSize1, nums2, numsSize2);

    return 0;
}

void merge(int* nums1, int m, int *nums2, int n)
{
    int* array;
    int i =0;
    int j = 0;
    int k = 0;

    array = (int*)calloc(m+n,sizeof(int));


    while(i < m && j < n) {
        if(nums1[i] < nums2[j]) {
            array[k++] = nums1[i++];
        } else {
            array[k++] = nums2[j++];
        }
    }
    if(j == n) {
        while(i < m) {
            array[k++] = nums1[i++];
        }
    }
    if(i == m) {
        while(j < n) {
            array[k++] = nums2[j++];
        }
    }

    for(i=0;i<(m+n);i++) {
        nums1[i] = array[i];
        printf("%d\t",nums1[i]);
    }

}
             



