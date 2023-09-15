#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 알파벳 사전순 정렬
int compareAlphabetical(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// 길이가 짧은 순 정렬
int compareByLength(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    
    // First, compare by length
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    if (len1 < len2) return -1;
    if (len1 > len2) return 1;
    
    // If lengths are equal, then compare alphabetically
    return strcmp(str1, str2);
}

// 길이가 짧은 순 정렬 -> 길이가 같으면 알파벳 사전순 정렬
int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    
    // 1.길이순 : Compare by length
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    if (len1 < len2) return -1;
    if (len1 > len2) return 1;
    
    // 2. 길이가 같다면 알파벳순
    return strcmp(str1, str2);
}

int main() {
    const char *arr[] = {"apple", "banana", "cherry", "date", "grape", "fig"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    // Sort the array of strings alphabetically using qsort()
    //qsort(arr, n, sizeof(const char *), compareAlphabetical);

    // Sort the sorted array by length using qsort()
    //qsort(arr, n, sizeof(const char *), compareByLength);
    qsort(arr, n, sizeof(const char *), compare);

    printf("\nSorted array by length and alphabetically: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    return 0;
}
