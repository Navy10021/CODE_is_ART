#include <iostream>
#include <cassert>

class IntArray {
private:
    int *myarray; // Dynamic array
    int used;     // Number of elements used
    int max_size; // Capacity of the array

public:
    // Constructor
    IntArray(int size = 10) : used(0), max_size(size) {
        myarray = new int[max_size];
    }

    // Deep Copy Constructor
    IntArray(const IntArray &source) : used(source.used), max_size(source.max_size) {
        myarray = new int[max_size];
        for (int i = 0; i < used; i++) {
            myarray[i] = source.myarray[i];
        }
    }

    // Overloading = (Assignment Operator)
    IntArray& operator=(const IntArray &source) {
        if (this == &source) return *this;

        delete[] myarray;

        used = source.used;
        max_size = source.max_size;
        myarray = new int[max_size];
        for (int i = 0; i < used; i++) {
            myarray[i] = source.myarray[i];
        }

        return *this;
    }

    // Operator[]
    int& operator[](int index) {
        assert(index >= 0 && index < used);
        return myarray[index];
    }

    // Destructor
    ~IntArray() {
        delete[] myarray;
    }

    // Resize method
    void resize(int newSize) {
        if (newSize <= max_size) return;

        int* newArray = new int[newSize];
        for (int i = 0; i < used; i++) {
            newArray[i] = myarray[i];
        }

        delete[] myarray;
        myarray = newArray;
        max_size = newSize;
    }

    // Insert method
    void insert(int index, int value) {
        if (index < 0 || index > used) return;

        if (used == max_size) {
            resize(max_size * 2);
        }

        for (int i = used; i > index; i--) {
            myarray[i] = myarray[i - 1];
        }

        myarray[index] = value;
        used++;
    }

    // Remove method
    void remove(int index) {
        if (index < 0 || index >= used) return;

        for (int i = index; i < used - 1; i++) {
            myarray[i] = myarray[i + 1];
        }

        used--;
    }

    // Used for demonstration purposes: print the array's contents
    void print() const {
        for (int i = 0; i < used; i++) {
            std::cout << myarray[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    IntArray arr(5);

    // Insert elements
    for (int i = 0; i < 5; i++) {
        arr.insert(i, i + 1);
    }

    std::cout << "Array after insertion: ";
    arr.print();

    // Resize
    arr.resize(10);
    std::cout << "Array after resizing to 10: ";
    arr.print();

    // Insert at index 3
    arr.insert(3, 99);
    std::cout << "Array after inserting 99 at index 3: ";
    arr.print();

    // Remove element at index 2
    arr.remove(2);
    std::cout << "Array after removing the element at index 2: ";
    arr.print();

    return 0;
}