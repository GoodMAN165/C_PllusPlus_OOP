#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    // Функция для ввода данных
    void input()
    {
        cout << "Введите числитель: ";
        cin >> numerator;
        do {
            cout << "Введите знаменатель (не 0): ";
            cin >> denominator;
            if (denominator == 0) std::cerr << "Ошибка: знаменатель не может быть нулем!\n";
        } while (denominator == 0);
    }

    void display() const {
        cout << numerator << "/" << denominator;
    }

    // Сложение
    Fraction add(const Fraction& other) const
    {
        Fraction res;
        res.numerator = (numerator * other.denominator) + (other.numerator * denominator);
        res.denominator = denominator * other.denominator;
        return res;
    }

    // Вычитание [cite: 10]
    Fraction subtract(const Fraction& other) const
    {
        Fraction res;
        res.numerator = (numerator * other.denominator) - (other.numerator * denominator);
        res.denominator = denominator * other.denominator;
        return res;
    }

    // Умножение
    Fraction multiply(const Fraction& other) const
    {
        Fraction res;
        res.numerator = numerator * other.numerator;
        res.denominator = denominator * other.denominator;
        return res;
    }

    // Деление
    Fraction divide(const Fraction& other) const
    {
        Fraction res;
        res.numerator = numerator * other.denominator;
        res.denominator = denominator * other.numerator;
        return res;
    }
};

#endif