#include <iostream>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        if (radius <= 0) {
            throw invalid_argument("Radius must be positive");
        }

        return radius * radius * 3.14159;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double getArea() const override {
        if (length <= 0 || width <= 0) {
            throw invalid_argument("Length and width must be positive");
        }

        return length * width;
    }
};

int main() {
    try {
        Shape* shapes[] = {new Circle(-1), new Rectangle(-2, 3)};

        for (Shape* shape : shapes) {
            cout << "Area: " << shape->getArea() << endl;
            delete shape;
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
