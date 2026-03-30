#include <iostream>
#include "Point.h"
#include "Student.h"


int main() {
    setlocale(LC_ALL, "Ru");

    Point p1(5.5, 10.0);
    p1.display();
    p1.save("point_data.txt");

    Student s1("Алексей Алексеев", "ПВ311");
    s1.display();

    return 0;
}