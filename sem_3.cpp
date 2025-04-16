#include <iostream>
#include <stdexcept>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0.0) {
            throw std::runtime_error("Division by zero complex number");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    Complex operator*(int scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    friend Complex operator*(int scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }

    // Префиксный инкремент
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Префиксный декремент
    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    // Постфиксный инкремент
    Complex operator++(int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    // Постфиксный декремент
    Complex operator--(int) {
        Complex temp = *this;
        real--;
        imag--;
        return temp;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

