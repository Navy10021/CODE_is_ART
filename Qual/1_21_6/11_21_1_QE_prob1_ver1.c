#include <stdio.h>
#include <stdlib.h>

int smallest_pos_int(int array[], int n) {
    int m = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > m) {
            m = array[i];
        }
    }

    int *l = (int*)calloc(m + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) {
            l[array[i] - 1] = 1;
        }
    }

    for (int i = 0; i < m + 1; i++) {
        if (l[i] == 0) {
            free(l);
            return i + 1;
        }
    }

    free(l);
    return m + 1;
}

int main() {
    int array1[] = {4, 7, -1, 1, 2};
    printf("%d\n", smallest_pos_int(array1, 5)); // Output: 3
    int array2[] = {100, 101, 102};
    printf("%d\n", smallest_pos_int(array2, 3)); // Output: 1
    int array3[] = {3, 2, 1, 0, -1};
    printf("%d\n", smallest_pos_int(array3, 5)); // Output: 4
    int array4[] = {3};
    printf("%d\n", smallest_pos_int(array4, 1)); // Output: 1
    int array5[] = {3, 1};
    printf("%d\n", smallest_pos_int(array5, 2)); // Output: 2

    return 0;
}
