#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>

using namespace std;

class Student
{
    char* fullName;
    static int studentCount;

public:
    // Делегирование конструкторов [cite: 75, 117]
    Student() : Student("Unknown") {}

    Student(const char* name) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        studentCount++;
    }

    ~Student() {
        delete[] fullName;
        studentCount--;
    }

    static int getStudentCount() {
        return studentCount;
    }

    void display() const {
        cout << "Student: " << fullName << endl;
    }
};

int Student::studentCount = 0;

#endif