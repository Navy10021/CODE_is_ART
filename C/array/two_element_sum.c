#include <stdio.h>

void findTwoElementsWithSum(int arr[], int length, int target) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Elements %d and %d sum up to %d\n", arr[i], arr[j], target);
                return; // Exit once a valid pair is found
            }
        }
    }
    printf("No elements found that sum up to %d\n", target);
}

int main() {
    int input[] = {3, 9, 2, 8, 5};
    int length = sizeof(input) / sizeof(input[0]);
    int target = 11;

    findTwoElementsWithSum(input, length, target);

    return 0;
}
