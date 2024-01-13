#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

// Geometric shapes
class Figure {
public:
    virtual double CalculateArea() const = 0;
    virtual double CalculateVolume() const { return 0.0; }
    virtual void DisplayInfo() const = 0;
    virtual ~Figure() {}
};

// Circle class
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double CalculateArea() const override {
        return 3.14 * radius * radius;
    }
    void DisplayInfo() const override {
        cout << "Type: Circle || Area: " << CalculateArea() << endl;
    }
};

// Cylinder class
class Cylinder : public Circle {
private:
    double height;

public:
    Cylinder(double r, double h) : Circle(r), height(h) {}

    double CalculateVolume() const override {
        return CalculateArea() * height;
    }
    void DisplayInfo() const override {
        cout << "Type: Cylinder || Volume: " << CalculateVolume() << " || Area: " << CalculateArea() << endl;
    }
};

// Square Class
class Square : public Figure {
private:
    double side;

public:
    Square(double s) : side(s) {}
    double getSide() const {
        return side;
    }
    double CalculateArea() const override {
        return side * side;
    }
    void DisplayInfo() const override {
        cout << "Type: Square || Area: " << CalculateArea() << endl;
    }
};

// Cube class : inheriting from Square
class Cube : public Square {
public:
    Cube(double side) : Square(side) {}

    double CalculateVolume() const override {
        return CalculateArea() * getSide();
    }
    void DisplayInfo() const override {
        cout << "Type: Cube || Volume: " << CalculateVolume() << " || Area: " << CalculateArea() << endl;
    }
};

// Rectangle class : inheriting from Square
class Rectangle : public Square {
private:
    double height;

public:
    Rectangle(double l, double w) : Square(l), height(w) {}

    double CalculateArea() const override {
        return getSide() * height;
    }
    void DisplayInfo() const override {
        cout << "Type: Rectangle || Area: " << CalculateArea() << endl;
    }
};

// Pyramid class : inheriting from Rectangle
class Pyramid : public Rectangle {
private:
    double height;

public:
    Pyramid(double l, double w, double h) : Rectangle(l, w), height(h) {}

    double CalculateVolume() const override {
        return CalculateArea() * height / 3.0;
    }
    void DisplayInfo() const override {
        cout << "Type: Pyramid || Volume: " << CalculateVolume() << " || Area: " << CalculateArea() << endl;
    }
};

class Triangle : public Figure {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double CalculateArea() const override {
        return 0.5 * base * height;
    }
    void DisplayInfo() const override {
        cout << "Type: Triangle || Area: " << CalculateArea() << endl;
    }
};

// Equilateral Triangle class : Inheriting from Triangle
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, (sqrt(3) / 2) * side) {}
    void DisplayInfo() const override {
        cout << "Type: Equilateral Triangle || Area: " << CalculateArea() << endl;
    }
};

// Hexagon class : Inheriting from Figure
class Hexagon : public Figure {
private:
    double side;

public:
    Hexagon(double s) : side(s) {}
    double CalculateArea() const override {
        return (3.0 / 2.0) * sqrt(3.0) * side * side;
    }
    void DisplayInfo() const override {
        cout << "Type: Hexagon || Area: " << CalculateArea() << endl;
    }
};

// ColorFigure class : Inheriting from Figure
class ColorFigure : public Figure {
private:
    Figure* figure;
    string color;

public:
    ColorFigure(Figure* fig, const string& c) : figure(fig), color(c) {}

    double CalculateArea() const override {
        return figure->CalculateArea();
    }

    double CalculateVolume() const override {
        return figure->CalculateVolume();
    }

    void DisplayInfo() const override {
        cout << "Colored " << color << " ";
        figure->DisplayInfo();
    }

    ~ColorFigure() {
        delete figure;
    }
};

// ThreeDimensionalFigure class : Inheriting from Figure
class ThreeDimensionalFigure : public Figure {
public:
    virtual double CalculateVolume() const = 0;
};

// Sphere class : Inheriting from ThreeDimensionalFigure
class Sphere : public ThreeDimensionalFigure {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    double CalculateArea() const override {
        return 4.0 * 3.14 * radius * radius;
    }

    double CalculateVolume() const override {
        return (4.0 / 3.0) * 3.14 * radius * radius * radius;
    }

    void DisplayInfo() const override {
        cout << "Type: Sphere || Volume: " << CalculateVolume() << " || Area: " << CalculateArea() << endl;
    }
};

// Figure Manager class
class FigureManager {
private:
    Figure* figureArr[15];
    int Idx;

public:
    FigureManager() : Idx(0) {}

    void AddFigure(Figure* fig) {
        if (Idx < 15) {
            figureArr[Idx++] = fig;
        }
        else {
            cout << "Cannot add more." << endl;
            delete fig;
        }
    }

    double TotalArea() const {
        double totalArea = 0.0;
        for (int i = 0; i < Idx; i++) {
            totalArea += figureArr[i]->CalculateArea();
        }
        return totalArea;
    }

    double AvgArea() const {
        if (Idx == 0)
            return 0.0;

        return TotalArea() / Idx;
    }

    void findMinMax() {
        Figure* minFigure = figureArr[0];
        Figure* maxFigure = figureArr[0];

        for (int i = 0; i < Idx; i++) {
            if (figureArr[i]->CalculateArea() < minFigure->CalculateArea())
                minFigure = figureArr[i];

            if (figureArr[i]->CalculateArea() > maxFigure->CalculateArea())
                maxFigure = figureArr[i];
        }
        cout << "MAX Figure: ";
        maxFigure->DisplayInfo();
        cout << "MIN Figure: ";
        minFigure->DisplayInfo();
    }

    void sortByArea() {
        sort(figureArr, figureArr + Idx, [](const Figure* a, const Figure* b) {
            return a->CalculateArea() > b->CalculateArea();
       
