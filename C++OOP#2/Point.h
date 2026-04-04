#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <fstream>

using namespace std;

class Point
{

    double x, y;
    static int pointCount;

public:
    // Делегирование конструкторов
    Point() : Point(0, 0) {}

    Point(double _x, double _y) : x(_x), y(_y)
    {
        pointCount++;
    }

    // Деструктор
    ~Point()
    {
        pointCount--;
    }


    static int getPointCount()
    {
        return pointCount;
    }


    inline void input()
    {
        cout << "Enter X and Y: ";
        cin >> x >> y;
    }

    inline void display() const
    {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    void save(const char* filename) const
    {
        ofstream out(filename);
        if (out.is_open()) out << x << " " << y;
    }
};

int Point::pointCount = 0;

#endif