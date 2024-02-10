#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <cmath> // For std::pow and std::sqrt

using namespace std;

class LinearRegression {
protected:
    double m; // Slope
    double b; // Intercept

public:
    LinearRegression() : m(0), b(0) {}

    virtual void fit(const vector<double>& x, const vector<double>& y) {
        if (x.size() != y.size() || x.empty()) {
            throw std::invalid_argument("Input vectors x and y must have the same size and cannot be empty.");
        }

        double x_mean = accumulate(x.begin(), x.end(), 0.0) / x.size();
        double y_mean = accumulate(y.begin(), y.end(), 0.0) / y.size();

        double numerator = 0.0, denominator = 0.0;
        for (size_t i = 0; i < x.size(); ++i) {
            numerator += (x[i] - x_mean) * (y[i] - y_mean);
            denominator += pow(x[i] - x_mean, 2);
        }

        m = numerator / denominator;
        b = y_mean - m * x_mean;

        cout << "Linear model fitted successfully." << endl;
    }

    virtual double predict(double x) {
        return m * x + b;
    }

    double coefficientOfDetermination(const vector<double>& x, const vector<double>& y) {
        if (x.size() != y.size() || x.empty()) {
            throw std::invalid_argument("Input vectors x and y must have the same size and cannot be empty.");
        }

        double y_mean = accumulate(y.begin(), y.end(), 0.0) / y.size();
        double ss_tot = 0.0; // Total sum of squares
        double ss_res = 0.0; // Residual sum of squares

        for (size_t i = 0; i < x.size(); ++i) {
            double y_pred = predict(x[i]);
            ss_tot += pow(y[i] - y_mean, 2);
            ss_res += pow(y[i] - y_pred, 2);
        }

        return 1 - (ss_res / ss_tot);
    }

    virtual ~LinearRegression() {}
};

int main() {
    LinearRegression model;
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 3, 2, 5, 7}; // Example data

    model.fit(x, y);

    // Demonstrate prediction
    cout << "Predicted value at x = 6: " << model.predict(6) << endl;

    // Evaluate model
    cout << "R² = " << model.coefficientOfDetermination(x, y) << endl;

    return 0;
}