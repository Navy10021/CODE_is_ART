#include <iostream>
#include <vector>
#include <cmath> // For exp()

using namespace std;

class LogisticRegression {
private:
    double m; // Weight
    double b; // Bias
    double learningRate;
    int iterations;

    double sigmoid(double z) const {
        return 1.0 / (1 + exp(-z));
    }

public:
    LogisticRegression(double lr = 0.01, int iter = 1000) : m(0), b(0), learningRate(lr), iterations(iter) {}

    void fit(const vector<double>& x, const vector<double>& y) {
        int n = x.size();

        for (int i = 0; i < iterations; i++) {
            double gradientM = 0, gradientB = 0;

            for (int j = 0; j < n; j++) {
                double prediction = sigmoid(m * x[j] + b);
                gradientM += x[j] * (prediction - y[j]);
                gradientB += prediction - y[j];
            }

            m -= learningRate * gradientM / n;
            b -= learningRate * gradientB / n;
        }
    }

    double predict(double x) {
        double z = m * x + b;
        double probability = sigmoid(z);
        return probability >= 0.5 ? 1 : 0; // Threshold at 0.5
    }
};

int main() {
    // Example usage
    LogisticRegression model;
    vector<double> x = {0.5, 2.3, 2.9}; // Example feature values
    vector<double> y = {0, 1, 1};       // Corresponding labels (0 or 1)

    model.fit(x, y);

    double testX = 1.0;
    cout << "Predicted class for x = " << testX << ": " << model.predict(testX) << endl;

    return 0;
}