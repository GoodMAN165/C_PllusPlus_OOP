#pragma once

using namespace std;

class Circle
{

    double radius;

public:
    Circle();
    Circle(double r);

    // Геттер для радиуса
    double getRadius() const;
    // Длина окружности
    double getCircumference() const;

    // Проверка на равенство радиусов (==)
    bool operator==(const Circle& other) const;

    // Сравнение длин двух окружностей (>)
    bool operator>(const Circle& other) const;

    // Изменение радиуса (+= и -=)
    Circle& operator+=(double r);
    Circle& operator-=(double r);

    void printInfo() const;
};