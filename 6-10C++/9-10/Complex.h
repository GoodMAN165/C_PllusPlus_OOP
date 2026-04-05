#pragma once

using namespace std;

class Complex
{
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Перегрузка +
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Перегрузка -
    friend Complex operator-(const Complex& c1, const Complex& c2)
    {
        return Complex(c1.real - c2.real, c1.imag - c2.imag);
    }

    // Ввод-вывод
    friend ostream& operator<<(ostream& os, const Complex& c)
    {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c)
    {
        cout << "Enter real and imag: ";
        is >> c.real >> c.imag;
        return is;
    }
};