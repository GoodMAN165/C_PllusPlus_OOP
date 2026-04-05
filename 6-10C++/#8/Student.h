#pragma once

#include <cstring>
#include <utility>

using namespace std;

class Student
{
    char* fullName;

public:
    Student() : fullName(nullptr) {}

    explicit Student(const char* name)
    {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        cout << "(Constructor) Allocated for: " << fullName << endl;
    }

    // Конструктор копирования
    Student(const Student& other)
    {
        if (other.fullName)
        {
            fullName = new char[strlen(other.fullName) + 1];
            strcpy(fullName, other.fullName);
        }
        else
        {
            fullName = nullptr;
        }
        cout << "(Copy Constructor) Copied: " << fullName << endl;
    }

    // Конструктор переноса
    Student(Student&& other) noexcept
    {
        fullName = other.fullName;
        other.fullName = nullptr;
        cout << "(Move Constructor) Moved resource from temporary object" << endl;
    }

    // Деструктор
    ~Student()
    {
        if (fullName)
        {
            cout << "(Destructor) Freeing memory for: " << fullName << endl;
            delete[] fullName;
        }
    }

    void showInfo() const
    {
        if (fullName) cout << "Student: " << fullName << endl;
        else cout << "Empty student object" << endl;
    }
};