#include <iostream>
#include <cassert>

class ArrayOfArray {
private:
    int **myarray; // An array of integer array pointers
    int used;      // Number of integer arrays currently used
    int max_size;  // Capacity of the array of integer arrays

public:
    // Constructor
    ArrayOfArray(int size = 10) : used(0), max_size(size) {
        myarray = new int*[max_size];
        for (int i = 0; i < max_size; ++i) {
            myarray[i] = nullptr; // Initialize all pointers to nullptr
        }
    }

    // Deep Copy Constructor
    ArrayOfArray(const ArrayOfArray &source) : used(source.used), max_size(source.max_size) {
        myarray = new int*[max_size];
        for (int i = 0; i < used; ++i) {
            int subArraySize = source.myarray[i][0];
            myarray[i] = new int[subArraySize + 1]; // +1 for the size storage
            for (int j = 0; j <= subArraySize; ++j) {
                myarray[i][j] = source.myarray[i][j];
            }
        }
    }

    // Overloading = (Assignment Operator)
    ArrayOfArray& operator=(const ArrayOfArray &source) {
        if (this != &source) {
            // Clean up existing myarray
            for (int i = 0; i < used; ++i) {
                delete[] myarray[i];
            }
            delete[] myarray;

            // Copy from source
            used = source.used;
            max_size = source.max_size;
            myarray = new int*[max_size];
            for (int i = 0; i < used; ++i) {
                int subArraySize = source.myarray[i][0];
                myarray[i] = new int[subArraySize + 1];
                for (int j = 0; j <= subArraySize; ++j) {
                    myarray[i][j] = source.myarray[i][j];
                }
            }
        }
        return *this;
    }

    // Operator[]
    int*& operator[](int index) {
        assert(index >= 0 && index < used);
        return myarray[index];
    }

    // Destructor
    ~ArrayOfArray() {
        for (int i = 0; i < used; ++i) {
            delete[] myarray[i];
        }
        delete[] myarray;
    }

    // Resize method
    void resize(int newSize) {
        if (newSize > max_size) {
            int **newArray = new int*[newSize];
            for (int i = 0; i < used; ++i) {
                newArray[i] = myarray[i];
            }
            for (int i = used; i < newSize; ++i) {
                newArray[i] = nullptr;
            }
            delete[] myarray;
            myarray = newArray;
            max_size = newSize;
        }
    }

    // Corrected Insert method
    void insert(int *subArray) {
        if (used == max_size) {
            resize(max_size * 2); // Double the size if necessary
        }
        int subArraySize = subArray[0];
        myarray[used] = new int[subArraySize + 1]; // +1 to store the size at the first index
        myarray[used][0] = subArraySize; // Store the size
        for (int i = 1; i <= subArraySize; ++i) {
            myarray[used][i] = subArray[i];
        }
        used++;
    }

    // Remove method
    void remove(int index) {
        assert(index >= 0 && index < used);
        delete[] myarray[index];
        for (int i = index; i < used - 1; ++i) {
            myarray[i] = myarray[i + 1];
        }
        myarray[used - 1] = nullptr;
        --used;
    }

    // Used for demonstration purposes: print the array's contents
    void print() const {
        for (int i = 0; i < used; ++i) {
            int subArraySize = myarray[i][0];
            std::cout << "Sub-array " << i << ": ";
            for (int j = 1; j <= subArraySize; ++j) {
                std::cout << myarray[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};