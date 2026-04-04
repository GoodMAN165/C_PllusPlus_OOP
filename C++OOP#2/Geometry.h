#ifndef GEOMETRY_H
#define GEOMETRY_H


using namespace std;

class Geometry
{
    static int calculationCount;

public:

    static double triangleArea(double base, double height) {
        calculationCount++;
        return 0.5 * base * height;
    }


    static double rectangleArea(double a, double b) {
        calculationCount++;
        return a * b;
    }

    // Функция для площади квадрата
    static double squareArea(double a) {
        calculationCount++;
        return a * a;
    }

    // Функция для площади ромба
    static double rhombusArea(double d1, double d2) {
        calculationCount++;
        return (d1 * d2) / 2.0;
    }

    // Подсчёт
    static int getCalculationCount() {
        return calculationCount;
    }
};


int Geometry::calculationCount = 0;

#endif