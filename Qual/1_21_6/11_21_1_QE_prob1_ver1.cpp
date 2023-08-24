#include <iostream>
#include <vector>

int smallest_pos_int(const std::vector<int>& array) {
    int m = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (array[i] > m) {
            m = array[i];
        }
    }

    std::vector<int> l(m + 1, 0);
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > 0) {
            l[array[i] - 1] = 1;
        }
    }

    for (int i = 0; i < m + 1; i++) {
        if (l[i] == 0) {
            return i + 1;
        }
    }

    return m + 1;
}

int main() {
    std::vector<int> array1 = {4, 7, -1, 1, 2};
    std::cout << smallest_pos_int(array1) << '\n'; // Output: 3
    std::vector<int> array2 = {100, 101, 102};
    std::cout << smallest_pos_int(array2) << '\n'; // Output: 1
    std::vector<int> array3 = {3, 2, 1, 0, -1};
    std::cout << smallest_pos_int(array3) << '\n'; // Output: 4
    std::vector<int> array4 = {3};
    std::cout << smallest_pos_int(array4) << '\n'; // Output: 1
    std::vector<int> array5 = {3, 1};
    std::cout << smallest_pos_int(array5) << '\n'; // Output: 2

    return 0;
}
