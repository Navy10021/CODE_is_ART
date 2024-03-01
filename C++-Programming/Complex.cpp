#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Destructor
    virtual ~Complex() {}

    // Getters
    double GetReal() const { return real; }
    double GetImag() const { return imag; }

    // Operator Overloads
    bool operator==(const Complex& rhs) const {
        return real == rhs.real && imag == rhs.imag;
    }

    bool operator!=(const Complex& rhs) const {
        return !(*this == rhs);
    }

    Complex operator+(const Complex& rhs) const {
        return Complex(real + rhs.real, imag + rhs.imag);
    }

    Complex operator-(const Complex& rhs) const {
        return Complex(real - rhs.real, imag - rhs.imag);
    }

    Complex operator*(const Complex& rhs) const {
        return Complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
    }

    Complex operator/(const Complex& rhs) const {
        double denominator = rhs.real * rhs.real + rhs.imag * rhs.imag;
        return Complex((real * rhs.real + imag * rhs.imag) / denominator, 
                       (imag * rhs.real - real * rhs.imag) / denominator);
    }

    // Magnitude
    double GetMagnitude() const {
        return std::sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex c1(3, 4), c2(1, -2), c3;

    // Arithmetic Operations
    c3 = c1 + c2;
    std::cout << "Addition: (" << c3.GetReal() << " + " << c3.GetImag() << "i)" << std::endl;

    c3 = c1 - c2;
    std::cout << "Subtraction: (" << c3.GetReal() << " - " << c3.GetImag() << "i)" << std::endl;

    c3 = c1 * c2;
    std::cout << "Multiplication: (" << c3.GetReal() << " * " << c3.GetImag() << "i)" << std::endl;

    c3 = c1 / c2;
    std::cout << "Division: (" << c3.GetReal() << " / " << c3.GetImag() << "i)" << std::endl;

    // Comparison
    if (c1 == c2) std::cout << "c1 and c2 are equal." << std::endl;
    if (c1 != c2) std::cout << "c1 and c2 are not equal." << std::endl;

    // Magnitude
    std::cout << "Magnitude of c1: " << c1.GetMagnitude() << std::endl;
    std::cout << "Magnitude of c2: " << c2.GetMagnitude() << std::endl;

    return 0;
}
