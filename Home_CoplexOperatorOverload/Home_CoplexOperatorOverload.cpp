#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    
    Complex() : real(0), imaginary(0) {}
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    
    void setReal(double r) { real = r; }
    void setImaginary(double i) { imaginary = i; }

    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImaginary);
    }

    
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        if (denominator == 0) {
            cout << "Error! Division by zero." << endl;
            return Complex(0, 0); 
        }

        double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
        double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(newReal, newImaginary);
    }

    void print() const {
        cout << real << (imaginary >= 0 ? " + " : " - ")
            << (imaginary >= 0 ? imaginary : -imaginary) << "i";
    }

  
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }

};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:" << endl;
    c1.input();

    cout << "Enter second complex number:" << endl;
    c2.input();

    cout << "Complex Number 1: ";
    c1.print();
    cout << endl;

    cout << "Complex Number 2: ";
    c2.print();
    cout << endl;

    cout << "Sum: ";
    (c1 + c2).print();
    cout << endl;

    cout << "Difference: ";
    (c1 - c2).print();
    cout << endl;

    cout << "Product: ";
    (c1 * c2).print();
    cout << endl;

    Complex quotient = c1 / c2;
    if (quotient.getReal() == 0 && quotient.getImaginary() == 0 && (c2.getReal() == 0 && c2.getImaginary() == 0)) {
        cout << "Cannot perform division by zero." << endl;
    }
    else {
        cout << "Quotient: ";
        quotient.print();
        cout << endl;
    }

    
}
