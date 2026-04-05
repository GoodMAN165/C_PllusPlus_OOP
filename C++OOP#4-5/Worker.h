#pragma once

#include <string>

using namespace std;

class Worker
{
    string fullName;
    string position;
    int hireYear;
    double salary;

public:
    // Explicit конструктор
    explicit Worker(string name = "", string pos = "", int year = 2020, double sal = 0.0)
        : fullName(name), position(pos), hireYear(year), salary(sal) {}

    // Функция отображения
    void display() const {
        cout << "Name: " << fullName << " | Position: " << position 
             << " | Salary: " << salary << " | Hired: " << hireYear << endl;
    }

    // Методы для фильтрации
    int getExperience(int currentYear) const { return currentYear - hireYear; }
    double getSalary() const { return salary; }
    string getPosition() const { return position; }
};