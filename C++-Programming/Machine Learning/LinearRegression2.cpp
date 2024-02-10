#include <iostream>
#include <vector>
#include <cmath> // For pow and sqrt functions

// Base class
class LinearRegression {
protected:
    double slope = 0.0;
    double intercept = 0.0;

public:
    LinearRegression() {}

    virtual ~LinearRegression() {} // Virtual destructor for proper cleanup

    void fit(const std::vector<double>& x, const std::vector<double>& y) {
        double x_mean = 0.0;
        double y_mean = 0.0;
        double num = 0.0;
        double den = 0.0;

        for (size_t i = 0; i < x.size(); ++i) {
            x_mean += x[i];
            y_mean += y[i];
        }
        x_mean /= x.size();
        y_mean /= y.size();

        for (size_t i = 0; i < x.size(); ++i) {
            num += (x[i] - x_mean) * (y[i] - y_mean);
            den += pow(x[i] - x_mean, 2);
        }

        slope = num / den;
        intercept = y_mean - slope * x_mean;
    }

    virtual double predict(double x) const {
        return slope * x + intercept;
    }

    double getSlope() const { return slope; }
    double getIntercept() const { return intercept; }
};

// Derived class
class CustomLinearRegression : public LinearRegression {
public:
    CustomLinearRegression() : LinearRegression() {}

    // Override the predict function
    double predict(double x) const override {
        // Direct call to base class implementation for demonstration
        return LinearRegression::predict(x);
    }

    // New functionality: Calculate the coefficient of determination (R^2)
    double calculateR2(const std::vector<double>& x, const std::vector<double>& y) {
        double total_variance = 0.0;
        double residual_variance = 0.0;
        double y_mean = 0.0;

        for (const auto& val : y) {
            y_mean += val;
        }
        y_mean /= y.size();

        for (size_t i = 0; i < y.size(); ++i) {
            double pred = predict(x[i]); // Uses the overridden predict
            total_variance += pow(y[i] - y_mean, 2);
            residual_variance += pow(y[i] - pred, 2);
        }

        return 1 - (residual_variance / total_variance);
    }
};

int main() {
    CustomLinearRegression model;
    std::vector<double> x = {1, 2, 3, 4, 5}; // Input feature
    std::vector<double> y = {2, 4, 6, 8, 10}; // Output

    model.fit(x, y);

    std::cout << "Model parameters:\n";
    std::cout << "Slope: " << model.getSlope() << std::endl;
    std::cout << "Intercept: " << model.getIntercept() << std::endl;

    // Calculate and display R^2
    double r2 = model.calculateR2(x, y);
    std::cout << "R^2: " << r2 << std::endl;

    return 0;
}