#include <iostream>
#include "Student.h"
#include <vector>

Student createTemporaryStudent() {
    return Student("John Doe");
}

int main() {
    cout << "Student Move" << endl;

    Student s1 = createTemporaryStudent();
    s1.showInfo();

    cout << "\nManual Move" << endl;
    Student s2 = std::move(s1);

    cout << "S2 (after move): "; s2.showInfo();
    cout << "S1 (after move): "; s1.showInfo(); // Будет пустым

    return 0;
}