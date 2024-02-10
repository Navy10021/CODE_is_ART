#include <iostream>
#include <vector>
#include <cmath> // For exp(), fabs()

using namespace std;

// Base Class 
class LogisticRegression {
protected:
    double m; // In the case of multivariate, this could be a vector<double>
    double b;
    double learningRate;
    int iterations;

    double sigmoid(double z) const {
        return 1.0 / (1 + exp(-z));
    }

public:
    LogisticRegression(double lr = 0.01, int iter = 1000) : m(0), b(0), learningRate(lr), iterations(iter) {}

    virtual void fit(const vector<double>& x, const vector<double>& y) {
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
        cout << "Logistic Regression Training..." << endl;
    }

    virtual double predict(double x) {
        double z = m * x + b;
        return sigmoid(z) >= 0.5 ? 1 : 0; // Threshold at 0.5
    }
};

// L2 Regularization term in the grdient calculations.
class LogisticRegressionWithL2 : public LogisticRegression {
protected:
    double lambda; // Regularization strength

public:
    LogisticRegressionWithL2(double lr = 0.01, int iter = 1000, double lambda = 0.1)
    : LogisticRegression(lr, iter), lambda(lambda) {}

    void fit(const vector<double>& x, const vector<double>& y) override {
        int n = x.size();

        for (int i = 0; i < iterations; i++) {
            double gradientM = 0, gradientB = 0;

            for (int j = 0; j < n; j++) {
                double prediction = sigmoid(m * x[j] + b);
                // Regularization in Gradient Calculation to prevent overfitting.
                gradientM += x[j] * (prediction - y[j]) + lambda * m;
                gradientB += prediction - y[j];
            }

            m -= learningRate * gradientM / n;
            b -= learningRate * gradientB / n;
        }
        cout << "Logistic Regression with L2 Regularization Training..." << endl;
    }
};

// Lasso Regularization.
class LogisticRegressionWithL1 : public LogisticRegression {
protected:
    double lambda; // Regularization strength

public:
    LogisticRegressionWithL1(double lr = 0.01, int iter = 1000, double lambda = 0.1)
    : LogisticRegression(lr, iter), lambda(lambda) {}

    void fit(const vector<double>& x, const vector<double>& y) override {
        int n = x.size();

        for (int i = 0; i < iterations; i++) {
            double gradientM = 0, gradientB = 0;

            for (int j = 0; j < n; j++) {
                double prediction = sigmoid(m * x[j] + b);
                gradientM += x[j] * (prediction - y[j]) + lambda * (m >= 0 ? 1 : -1); // Subgradient for L1
                gradientB += prediction - y[j];
            }

            m -= learningRate * gradientM / n;
            b -= learningRate * gradientB / n;
        }
        cout << "Logistic Regression L1 Regularization Training..." << endl;
    }
};

// ElasticNet Regularization
class LogisticRegressionWithElasticNet : public LogisticRegression {
protected:
    double lambda1; // L1 regularization strength
    double lambda2; // L2 regularization strength
    double alpha;   // Mixing parameter, alpha * L1 + (1 - alpha) * L2

public:
    LogisticRegressionWithElasticNet(double lr = 0.01, int iter = 1000, double lambda1 = 0.1, double lambda2 = 0.1, double alpha = 0.5)
    : LogisticRegression(lr, iter), lambda1(lambda1), lambda2(lambda2), alpha(alpha) {}

    void fit(const vector<double>& x, const vector<double>& y) override {
        int n = x.size();

        for (int i = 0; i < iterations; i++) {
            double gradientM = 0, gradientB = 0;

            for (int j = 0; j < n; j++) {
                double prediction = sigmoid(m * x[j] + b);
                // Including both L1 and L2 regularization in the gradient calculation
                double l1_term = lambda1 * (m >= 0 ? 1 : -1);
                double l2_term = lambda2 * m;
                gradientM += x[j] * (prediction - y[j]) + alpha * l1_term + (1 - alpha) * l2_term;
                gradientB += prediction - y[j]; // Bias is not regularized
            }

            m -= learningRate * gradientM / n;
            b -= learningRate * gradientB / n;
        }
        cout << "Logistic Regression with Elastic Net Regularization Training..." << endl;
    }
};

// Stochastic Gradient Descent(SGD)
// SGD update the model parameters not after computing gradient over the entire dataset but for each trainig example one by one 
class LogisticRegressionSGD : public LogisticRegression {
public:
    LogisticRegressionSGD(double lr = 0.01, int iter = 1000)
    : LogisticRegression(lr, iter) {}

    void fit(const vector<double>& x, const vector<double>& y) override {
        int n = x.size();
        for (int i = 0; i < iterations; i++) {
            for (int j = 0; j < n; j++) {
                double prediction = sigmoid(m * x[j] + b);
                double gradientM = x[j] * (prediction - y[j]);
                double gradientB = prediction - y[j];

                // Update parameters for each training example
                m -= learningRate * gradientM;
                b -= learningRate * gradientB;
            }
        }
        cout << "Logistic Regression with SGD Training..." << endl;
    }
};

int main() {
    // Example usage
    LogisticRegressionWithElasticNet model(0.01, 1000, 0.05, 0.05, 0.5); // Balanced L1 and L2 regularization
    vector<double> x = {0.5, 2.3, 2.9}; // Example feature values
    vector<double> y = {0, 1, 1};       // Corresponding labels (0 or 1)

    model.fit(x, y);

    double testX = 1.0;
    cout << "Predicted class for x = " << testX << ": " << model.predict(testX) << endl;

    return 0;
}