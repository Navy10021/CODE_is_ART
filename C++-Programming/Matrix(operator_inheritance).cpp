#include <iostream>
#include <vector>

using namespace std;

class Matrix{
    private:
        vector<vector<int>> data;

    public:
        Matrix(const vector<vector<int>>& matrix)
            : data(matrix) {}

        virtual void ShowMatrix() const{
            for (const auto& row : data){
                for (int element : row){
                    cout << element << " ";
                }
                cout << endl;
            }
        }

        Matrix operator+(const Matrix& other) const{
            if (data.size() != other.data.size() || data[0].size() != other.data[0].size()){
                cerr << "Error : Matrix dimensions mismatch." << endl;
                return Matrix({});
            }

            vector<vector<int>> result;
            for (size_t i = 0; i < data.size(); i++){
                vector<int> row;
                for (size_t j = 0; j < data[i].size(); j++){
                    row.push_back(data[i][j] + other.data[i][j]);
                }
                result.push_back(row);
            }
            return Matrix(result);
        }

        Matrix operator-(const Matrix& other) const{
            if (data.size() != other.data.size() || data[0].size() != other.data[0].size()){
                cerr << "Error : Matrix dimensions mismatch." << endl;
                return Matrix({});
            }

            vector<vector<int>> result;
            for (size_t i = 0; i < data.size(); i++){
                vector<int> row;
                for (size_t j = 0; j < data[i].size(); j++){
                    row.push_back(data[i][j] - other.data[i][j]);
                }
                result.push_back(row);
            }
            return Matrix(result);
        }
        // Multipication
        Matrix operator*(const Matrix& other) const{
            if (data[0].size() != other.data.size()){
                cerr << "Error : Matrix dimensions mismatch." << endl;
                return Matrix({});
            }

            vector<vector<int>> result(data.size(), vector<int>(other.data[0].size(), 0));
            for (size_t i = 0; i < data.size(); i++){
                for (size_t j = 0; j < other.data[0].size(); j++){
                    for(size_t k = 0; k < other.data.size(); k++){
                        result[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return Matrix(result);
        }
        // Scalar product
        Matrix operator*(int scalar) const{
            vector<vector<int>> result = data;
            for (auto& row : result){
                for (int& element : row){
                    element *= scalar;
                }
            }
            return Matrix(result);
        }
        // Dot product
        int DotProduct(const Matrix& other) const{
            if (data.size() != other.data.size() || data[0].size() != other.data[0].size()){
                cerr << "Error : Matrix dimensions mismatch." << endl;
                return 0;
            }
            int result = 0;
            for (size_t i = 0; i < data.size(); i++){
                for (size_t j = 0; j < data[i].size(); j++){
                    result += data[i][j] * other.data[i][j];
                }
            }
            return result;
        }

        bool operator==(const Matrix& other) const{
            return data == other.data;
        }

        bool operator!=(const Matrix& other) const{
            return data != other.data;
        }

        Matrix& operator+=(const Matrix& other){
            *this = *this + other;
            return *this;
        }

        Matrix& operator-=(const Matrix& other){
            *this = *this - other;
            return *this;
        }

        Matrix Transpose() const{
            vector<vector<int>> result(data[0].size(), vector<int>(data.size(),0));
            for (size_t i = 0; i < data.size(); i++){
                for (size_t j = 0; j < data[0].size(); j++){
                    result[j][i] = data[i][j];
                }
            }
            return Matrix(result);
        }
        
};


// Derived Class
class Matrix2 : public Matrix{
    public :
        using Matrix::Matrix;  // Inheriting constructor

        // Additional function specific to Matrix 2 class

        // override
        void ShowMatrix() const override {
            cout << "This is Matrix Two class" << endl;
            Matrix::ShowMatrix();
        }

        int DotProduct(const Matrix& other) const{
            cout << "This is Matris Two class" << endl;
            return Matrix::DotProduct(other);
        }
};

int main(){
    // Example
    Matrix m1({{1, 2}, {3, 4}});
    Matrix m2({{5, 6}, {7, 8}});
    Matrix2 m3({{1, 1}, {1, 1}});
    Matrix res_add = m1 + m2;
    Matrix res_sub = m1 - m2;
    Matrix res_mul = m1 * m2;
    Matrix res_scalrProd = m1 * 10;
    int res_dotProd = m1.DotProduct(m2);
    Matrix m1_trans = m1.Transpose();
        
    cout << "Matrix 1 : " << endl;
    m1.ShowMatrix();
    cout << "Matrix 3 : " << endl;
    m3.ShowMatrix();
    m1 += m3;
    cout << "-------" << endl;
    m1.ShowMatrix();
    m1 -= m3;
    cout << "-------" << endl;
    m1.ShowMatrix();
    cout << "Transposed Matrix 1 : " << endl;
    m1_trans.ShowMatrix();
    cout << "Matrix 2 : " << endl;
    m2.ShowMatrix();
    cout << "M1 + M2 : " << endl;
    res_add.ShowMatrix();
    cout << "M1 - M2 : " << endl;
    res_sub.ShowMatrix();
    cout << "M1 * M2 : " << endl;
    res_mul.ShowMatrix();
    cout << "M1 * 10 : " << endl;
    res_scalrProd.ShowMatrix();
    cout << "M1 dot M2 : " << res_dotProd << endl;
    
    return 0;
}