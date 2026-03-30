#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <fstream>

using namespace std;

class Point
{
    double x;
    double y;

public:
    // Конструкторы
    Point() : x(0), y(0) {} 
    Point(double _x, double _y) : x(_x), y(_y) {}

    // Аксессоры
    inline double getX() const { return x; }
    inline double getY() const { return y; }
    inline void setX(double _x) { x = _x; }
    inline void setY(double _y) { y = _y; }

    // Функции для ввода и вывода
    inline void input() {
        cout << "Введите x: "; cin >> x;
        cout << "Введите y: "; cin >> y;
    }

    inline void display() const {
        cout << "Точка(" << x << ", " << y << ")" << endl;
    }

    // Сохранение в файл
    void save(const char* filename) const {
        ofstream out(filename);
        if (out.is_open()) {
            out << x << " " << y;
            out.close();
        }
    }

    // Загрузка из файла
    void load(const char* filename) {
        ifstream in(filename);
        if (in.is_open()) {
            in >> x >> y;
            in.close();
        }
    }
};

#endif