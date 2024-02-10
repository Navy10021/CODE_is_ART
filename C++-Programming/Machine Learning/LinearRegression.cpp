#include <iostream>
#include <vector>

using namespace std;

class LinearRegression{
    private:
        double m;   // Slope 
        double b;   // Intercept 
    
    public:
        LinearRegression() : m(0), b(0) {}  // Constructor
        
        void fit(const vector<double>& x, const vector<double>& y){
            if (x.size() != y.size() || x.empty()){
                cout << "Invalid data." << endl;
                return;
            }
            
            double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
            int n = x.size();
            
            for (int i = 0; i < n; i++){
                sumX += x[i];
                sumY += y[i];
                sumXY += x[i] * y[i];
                sumXX += x[i] * x[i];
            }
            double meanX = sumX / n;
            double meanY = sumY / n;
            
            m = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
            b = meanY - m * meanX;
        }
        
        double predict(double x){
            return m * x + b;
        }
};

int main(){
    LinearRegression model;
    vector<double> x = {1,2,3,4,5};
    vector<double> y = {2,3,4,5,6};
    
    model.fit(x, y);
    
    double x_pred = 15;
    double y_pred = model.predict(x_pred);
    
    cout << "Predicted value at x = " << x_pred << " is y = " << y_pred << endl;
    return 0;
}