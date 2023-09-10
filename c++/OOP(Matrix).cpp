#include <iostream>
using namespace std;

class Matrix{
    private:
        int** data;     // data-> int rows[] -> int cols
        size_t rows;
        size_t cols;

    public:
        // Constructor
        Matrix(size_t numRows, size_t numCols) : rows(numRows), cols(numCols) {
            data = new int* [rows];  // allocate rows size memory
            for (size_t i = 0; i < rows; i++){
                data[i] = new int[cols]();
            }
        }

        // Function 1 : set values in the matrix
        void setValue(size_t row, size_t col, int val){
            if (row < rows && col < cols){
                data[row][col] = val;
            }
        }

        // Function 2 : Display
        void display() const{
            for (size_t i=0; i<rows; i++){
                for (size_t j=0; j<cols; j++){
                    cout << data[i][j] << " ";
                }
                cout << "\n";
            }
        }

        // Function 3 : perform add(+)
        Matrix add(const Matrix& other) const {
            if (rows != other.rows || cols != other.cols){
                throw runtime_error("Matrix dimenstions do not match.");
            }
            Matrix res(rows, cols);
            for (size_t i = 0; i < rows; i++){
                for (size_t j = 0; j < cols; j++){
                    res.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return res;
        }

        // Function 3 : perform subtract(-)
        Matrix subtract(const Matrix& other) const {
            if (rows != other.rows || cols != other.cols){
                throw runtime_error("Matrix dimenstions do not match.");
            }
            Matrix res(rows, cols);
            for (size_t i = 0; i < rows; i++){
                for (size_t j = 0; j < cols; j++){
                    res.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
            return res;
        }

        // Function 4 : perform Scalar multiplication
        Matrix scalarMultiply(int scalar) const{
            Matrix res(rows, cols);
            for (size_t i = 0; i < rows; i++){
                for (size_t j = 0; j < cols; j++){
                    res.data[i][j] = data[i][j] * scalar;
                }
            }
            return res;
        }

        // Function 5 : Multiply
        Matrix mutiply(const Matrix& other) const{
            if (cols != other.rows){
                throw runtime_error("Matrix dimenstions do not match.");
            }
            Matrix res(rows, other.cols);
            for (size_t i = 0; i < rows; i++){
                for (size_t j = 0; j < other.cols; j++){
                    for (size_t k = 0; k < cols; k++){
                        res.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return res;
        }


        // Function 6 : Transpose
        Matrix transpose() const{
            Matrix transposed(cols, rows);
            for (size_t i = 0; i < rows; i++){
                for (size_t j = 0; j < cols; j++){
                    transposed.data[j][i] = data[i][j];
                }
            }
            return transposed;
        }

    // Destructor to release memory
    ~Matrix(){
        for (size_t i = 0; i < rows; i++){
            delete[] data[i];
        }
        delete[] data;
    }
};


int main(){
    Matrix A(2, 3);
    A.setValue(0, 0, 1);
    A.setValue(0, 1, 2);
    A.setValue(0, 2, 3);
    A.setValue(1, 0, 4);
    A.setValue(1, 1, 5);
    A.setValue(1, 2, 6);

    cout << "Matrix A : " << "\n";
    A.display();

    Matrix B(2, 3);
    B.setValue(0, 0, 6);
    B.setValue(0, 1, 5);
    B.setValue(0, 2, 4);
    B.setValue(1, 0, 3);
    B.setValue(1, 1, 2);
    B.setValue(1, 2, 1);

    cout << "Matrix B : " << "\n";
    B.display();

    Matrix res1 = A.add(B);
    cout << "A + B : " << "\n";
    res1.display();

    Matrix res2 = A.subtract(B);
    cout << "A - B : " << "\n";
    res2.display();

    Matrix res3 = A.scalarMultiply(10);
    cout << "A * 10 : " << "\n";
    res3.display();

    Matrix C(3, 2);
    C.setValue(0, 0, 6);
    C.setValue(0, 1, 5);
    C.setValue(1, 0, 4);
    C.setValue(1, 1, 3);
    C.setValue(2, 0, 2);
    C.setValue(2, 1, 1);

    cout << "Matrix C : " << "\n";
    C.display();

    Matrix res4 = A.mutiply(C);     // 3X2 * 2X3 = 2X2
    cout << "A * C : " << "\n";
    res4.display();

    Matrix res5 = C.transpose();
    cout << "C^T" << "\n";
    res5.display();
}


