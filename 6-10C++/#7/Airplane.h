#pragma once

#include <string>

using namespace std;

class Airplane
{

    string type;
    int passengers;
    int maxPassengers;

public:
    Airplane();
    Airplane(string t, int mP);

    // Проверка на равенство (==)
    bool operator==(const Airplane& other) const;

    // Увеличение пассажиров
    Airplane& operator++();

    // уменьшение пассажиров
    Airplane& operator--();

    // Сравнение по макс. количеству пассажиров (>)
    bool operator>(const Airplane& other) const;

    void printInfo() const;
};