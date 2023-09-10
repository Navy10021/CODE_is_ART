#include <stdio.h>
#include <stdlib.h>

int* mergeSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* mergedArray = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i = 0;  // nums1의 인덱스
    int j = 0;  // nums2의 인덱스
    int k = 0;  // mergedArray의 인덱스

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            mergedArray[k] = nums1[i];
            i++;
        } else {
            mergedArray[k] = nums2[j];
            j++;
        }
        k++;
    }

    // 남은 요소들을 병합
    while (i < nums1Size) {
        mergedArray[k] = nums1[i];
        i++;
        k++;
    }
    
    while (j < nums2Size) {
        mergedArray[k] = nums2[j];
        j++;
        k++;
    }

    *returnSize = nums1Size + nums2Size;
    return mergedArray;
}

int main() {
    int nums1[] = {1, 3, 5};
    int nums1Size = 3;
    int nums2[] = {2, 4, 6};
    int nums2Size = 3;
    int returnSize;

    int* mergedArray = mergeSortedArrays(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Merged Sorted Array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    // 메모리 해제
    free(mergedArray);

    return 0;
}
