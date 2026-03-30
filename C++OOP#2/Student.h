#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    char* fullName;
    char birthDate[15];
    char phone[20];
    char city[30];
    char country[30];
    char schoolName[50];
    char schoolCity[30];
    char schoolCountry[30];
    char groupNumber[15];

public:
    // Конструктор
    Student(const char* name = "Unknown", const char* group = "000") {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strcpy(groupNumber, group);
        // Остальные поля можно инициализировать по умолчанию
    }

    // Деструктор
    ~Student() {
        delete[] fullName;
    }

    // Аксессор
    inline const char* getFullName() const { return fullName; }

    // Функция ввода данных
    void input()
    {
        char buffer[256];
        cout << "Введите ФИО: ";
        cin.ignore();
        cin.getline(buffer, 255);


        delete[] fullName;
        fullName = new char[strlen(buffer) + 1];
        strcpy(fullName, buffer);

        cout << "Введите номер группы: ";
        cin >> groupNumber;

    }
    // Функция вывода данных
    inline void display() const {
        cout << "Студент: " << fullName << " | Группа: " << groupNumber << endl;
    }
};

#endif