#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() = 0;
    virtual double perimetr() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        std::cout << "площадь - ";
        return 3.14 * radius * radius;
    }
    double perimetr() override {
        std::cout << "периметр - ";
        return 2 * 3.14 * radius;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double a) : side(a) {}
    double area() override {
        std::cout << "площадь - ";
        return side * side;
    }
    double perimetr() override {
        std::cout << "периметр - ";
        return 4 * side;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double length;
public:
    Rectangle(double a, double b) : width(a), length(b) {}
    double area() override {
        std::cout << "площадь - ";
        return width * length;
    }
    double perimetr() override {
        std::cout << "периметр - ";
        return 2 * (width + length);
    }
};

class Ellipse : public Shape {
private:
    double large_semi_axis;
    double small_semi_axis;
public:
    Ellipse(double a, double b) : large_semi_axis(a), small_semi_axis(b) {}
    double area() override {
        std::cout << "площадь - ";
        return 3.14 * large_semi_axis * small_semi_axis;
    }
    double perimetr() override {
        std::cout << "периметр - ";
        double h = pow((large_semi_axis - small_semi_axis), 2) / pow((large_semi_axis + small_semi_axis), 2);
        return 3.14 * (large_semi_axis + small_semi_axis) * (1 + 3 * h / (10 + sqrt(4 - 3 * h)));
    }
};

class Rhomb : public Shape {
private:
    double side;
    double angle;
public:
    Rhomb(double a, double angle_degrees) : side(a), angle(angle_degrees * 3.14 / 180) {}
    double area() override {
        std::cout << "площадь - ";
        return side * side * sin(angle);
    }
    double perimetr() override {
        std::cout << "периметр - ";
        return side * 4;
    }
};


int main() {
    Shape* shapes[5];  // Массив из 5 указателей

    shapes[0] = new Circle(5.0);
    shapes[1] = new Square(4.0);
    shapes[2] = new Rectangle(3.0, 6.0);
    shapes[3] = new Ellipse(5.0, 3.0);
    shapes[4] = new Rhomb(4.0, 45.0);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Фигура " << i+1 << std::endl;
        std::cout << shapes[i]->area()<< std::endl;
        std::cout << shapes[i]->perimetr()<<std::endl;
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; ++i) {
        delete shapes[i];
    }

    return 0;
}
