#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return strcmp((const char*)a, (const char*)b);
}

int main() {
    const int MAX_LEN = 100;
    const int MAX_NUM = 5;
    char strings[MAX_NUM][MAX_LEN];

    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%s", strings[i]);
    }

    qsort(strings, MAX_NUM, sizeof(strings[0]), compare);

    for (int i = 0; i < MAX_NUM; i++) {
        printf("%s  ", strings[i]);
    }
    printf("\n");

    return 0;
}