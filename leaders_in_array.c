#include <stdio.h>
#include <stdlib.h>

int* leaders_in_array(int* a, int size_array, int*);

int main()
{
    int *a;
    int size_array;
    int i = 0;
    int *leaders = NULL;
    int leader_count = 0;

    printf("Enter size of array:");
    scanf("%d", &size_array);

    a = (int*)calloc(size_array, sizeof(int));

    for(i = 0; i < size_array; i++) {
        printf("Enter %dth element:", i);
        scanf("%d",&a[i]);
    }

    leaders = leaders_in_array(a, size_array, &leader_count);
    for(i = leader_count; i >= 0; i--) {
        printf("%d\n", leaders[i]);
    }

    return 0;
}

int* leaders_in_array(int* a, int size_array, int *leader_count)
{
    int max = -9999;
    int i=0;
    int j= 0;
    int *leader = NULL;

    leader = (int*)calloc(size_array, sizeof(int));

    if(size_array > 0) {
        max = a[size_array-1];
        leader[i] = a[size_array-1];

        for(j = size_array-2; j >= 0; j--) {
            if(a[j] > max) {
                leader[++i] = a[j];
                max = a[j];
            }
        }
    }
    (*leader_count) = i;
    
    return leader;
}
