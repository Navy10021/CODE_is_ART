#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// Geometric shapes 
// Base class
class Figure{
    public:
        virtual double CalculateArea() const = 0; 
        virtual void DisplayInfo() const = 0;
        virtual ~Figure() {}
};

// Circle class 
class Circle : public Figure{
    private:
        double radius; 
    public:
        Circle(double r) : radius(r) {} 
        double CalculateArea() const override {
            return 3.14 * radius * radius;
        }
        void DisplayInfo() const override{
            cout << "Type : Circle || Area : " << CalculateArea() << endl;
        }
};

// Square Class
class Square : public Figure{
    private:
        double side;
    public:
        Square(double s) : side(s) {}
        double getSide() const{
            return side;
        }
        double CalculateArea() const override {
            return side * side;
        }
        void DisplayInfo() const override{
            cout << "Type : Square || Area : " << CalculateArea() << endl;
        }      
};

// Rectengle class : inheriting from Sqare 
class Rectangle : public Square{
    private:
        double height;
    public:
        Rectangle(double l, double w) : Square(l), height(w) {} 

        double CalculateArea() const override {
            return getSide() * height;
        }
        void DisplayInfo() const override{
            cout << "Type : Rectangle || Area : " << CalculateArea() << endl;
        }
};

class Triangle : public Figure {
    private:
        double base; 
        double height;
    public:
        Triangle(double b, double h) : base(b), height(h) {}

        double CalculateArea() const override{
            return 0.5 * base * height;
        }
        void DisplayInfo() const override{
            cout << "Type : Triangle || Area : " << CalculateArea() << endl;
        }
};

// Equilateral Triangle class : Inheriting from Triangle
class EquilateralTriangle : public Triangle{
    public:
        EquilateralTriangle(double side) : Triangle(side, (sqrt(3) / 2) * side) {}
        void DisplayInfo() const override{
            cout << "Tyle : Equilateral Triangle || Area : " << CalculateArea() << endl;
        }
};

// Figure Manager class
class FigureManager{
    private:
        Figure* figureArr[10];
        int Idx;
    public:
        FigureManager() : Idx(0) {}

        void AddFigure (Figure * fig){
            if (Idx < 10){
                figureArr[Idx++] = fig;
            }
            else{
                cout << "Cannot add more." << endl;
                delete fig;
            }
        }
        double TotalArea() const{
            double totalArea = 0.0;
            for (int i = 0; i < Idx; i++){
                totalArea += figureArr[i]->CalculateArea();
            }
            return totalArea;
        }
        double AvgArea() const{
            if (Idx == 0)
                return 0.0;

            return TotalArea() / Idx;
        }
        void findMinMax() {
            Figure * minFigure = figureArr[0];
            Figure * maxFigure = figureArr[0];

            for (int i = 0; i < Idx; i++){
                if (figureArr[i]->CalculateArea() < minFigure->CalculateArea())
                    minFigure = figureArr[i];

                if (figureArr[i]->CalculateArea() > maxFigure->CalculateArea())
                    maxFigure = figureArr[i];
            }
            cout << "MAX Figure : ";
            maxFigure->DisplayInfo();
            cout << "MIN Figure : ";
            minFigure->DisplayInfo();
        }

        void sortByArea(){
            sort(figureArr, figureArr + Idx, [](const Figure* a, const Figure* b){
                return a->CalculateArea() > b->CalculateArea();
            });
        }
        void DisplayFigure() const{
            for (int i = 0; i < Idx; i++){
                figureArr[i]->DisplayInfo();
            }
        }
        ~FigureManager(){
            for (int i = 0; i < Idx; i++){
                delete figureArr[i];
            }
        }
};

int main(void){
    FigureManager manager;

    manager.AddFigure(new Circle(5.0));
    manager.AddFigure(new Square(4.0));
    manager.AddFigure(new Rectangle(3.0, 5.0));
    manager.AddFigure(new EquilateralTriangle(5.0));

    // Display
    cout << "Total Area of all figures : " << manager.TotalArea() << endl;

    cout << "Average Area of all figures : " << manager.AvgArea() << endl;

    manager.sortByArea();
    cout << "Sorted Figures by Area (Descending order) : " << endl;
    manager.DisplayFigure();

    manager.findMinMax();
    
    return 0;
}













