#include <iostream>
#include <vector>
#include <cmath>

int smallest_pos_int(std::vector<int>& array) {
    int j = 0;

    // Move all non-positive numbers to the left
    for (int i = 0; i < array.size(); i++) {
        if (array[i] <= 0) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
        }
    }

    // Consider only the positive part of the array
    int m = array.size() - j;

    // Mark the elements using their index
    for (int i = 0; i < m; i++) {
        int num = std::abs(array[j + i]);
        if (num <= m && array[j + num - 1] > 0) {
            array[j + num - 1] = -array[j + num - 1];
        }
    }

    // Find the first positive number in the modified array
    for (int i = 0; i < m; i++) {
        if (array[j + i] > 0) {
            return i + 1;
        }
    }

    return m + 1;
}

int main() {
    std::vector<int> array1 = {4, 7, -1, 1, 2};
    std::vector<int> array2 = {100, 101, 102};
    std::vector<int> array3 = {3, 2, 1, 0, -1};

    std::cout << smallest_pos_int(array1) << '\n'; // Output: 3
    std::cout << smallest_pos_int(array2) << '\n'; // Output: 1
    std::cout << smallest_pos_int(array3) << '\n'; // Output: 4

    return 0;
}
